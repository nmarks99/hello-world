#include <cmath>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/node.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/loop.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

using namespace ftxui;

std::vector<double> arange(double start, double stop, double step) {
    std::vector<double> out;
    double vi = start;
    while (vi <= stop) {
        out.push_back(vi);
        vi += step;
    }
    return out;
}

double linear_map(double value, double a1, double a2, double b1, double b2) {
    const double m = (b2 - b1) / (a2 - a1);
    const double b = b1 - m * a1;
    return m * value + b;
}

Component LinePlot(std::vector<double> x, std::vector<double> y) {
    class Impl : public ComponentBase {
      public:
        Impl(std::vector<double> x, std::vector<double> y) : x_(std::move(x)), y_(std::move(y)) {
            // default "auto-scale" to fit the plot to the canvas
            auto xminmax = std::minmax_element(x_.begin(), x_.end());
            auto yminmax = std::minmax_element(y_.begin(), y_.end());
            xmin_ = *xminmax.first;
            xmax_ = *xminmax.second;
            ymin_ = *yminmax.first;
            ymax_ = *yminmax.second;
            xout_.resize(x_.size());
            yout_.resize(x_.size());
        }

        // void SetLimits(std::pair<double, double> xlims, std::pair<double, double> ylims) {
            // xmin_ = xlims.first;
            // xmax_ = xlims.second;
            // ymin_ = ylims.first;
            // ymax_ = ylims.second;
        // }

        Element OnRender() override {
            auto can = canvas([&](Canvas &c) {
                // draw y ticks
                for (size_t i = 0; i < c.height(); i++) {
                    if (i % 4 == 0) {
                        c.DrawText(0, i, "_ ");
                    }
                }

                // remake integer data for drawing only when canvas is resized
                if (c.width() != canvas_width_last_ || c.height() != canvas_height_last_) {
                    std::transform(x_.begin(), x_.end(), xout_.begin(), [&](auto v) {
                        return static_cast<int>(linear_map(v, xmin_, xmax_, 0, c.width()));
                    });
                    std::transform(y_.begin(), y_.end(), yout_.begin(), [&](auto v) {
                        return -static_cast<int>(linear_map(v, ymin_, ymax_, 0, c.height() - 4)) + c.height()-4;
                    });
                }

                // draw line plot
                for (size_t i = 0; i < x_.size(); i++) {
                    c.DrawPoint(xout_.at(i), yout_.at(i), true, line_color_);
                }

                canvas_width_last_ = c.width();
                canvas_height_last_ = c.height();
            });
            return can | flex;
        };

      private:
        std::vector<double> x_, y_;
        std::vector<int> xout_, yout_;
        double xmin_, xmax_, ymin_, ymax_;
        Color line_color_ = Color::Blue;
        double canvas_width_last_ = 0;
        double canvas_height_last_ = 0;
    };

    return Make<Impl>(std::move(x), std::move(y));
}

int main() {

    auto screen = ScreenInteractive::Fullscreen();

    auto x = arange(0, 2 * M_PI, 0.01);
    std::vector<double> y(x.size());
    std::transform(x.begin(), x.end(), y.begin(), [](double v) { return std::sin(v); });
    auto plot = LinePlot(x, y);

    // // Main container to define interactivity of components
    auto main_container = Container::Vertical({
    });

    // Main renderer to define visual layout of components and elements
    auto main_renderer = Renderer(main_container, [&] {
        return vbox({
            // plot_renderer->Render() | flex | border,
            plot->Render(),
            // vbox({
                // hbox({text("X-Range: "), xmin_inp->Render() | size(WIDTH, EQUAL, 10), separatorEmpty(),
                      // xmax_inp->Render() | size(WIDTH, EQUAL, 10)}),
                // hbox({text("Y-Range: "), ymin_inp->Render() | size(WIDTH, EQUAL, 10), separatorEmpty(),
                      // ymax_inp->Render() | size(WIDTH, EQUAL, 10)}),
            // }) | border |
                // size(HEIGHT, EQUAL, 10),
            // paragraph("Here is some text\nthat might\ntake up many lines?") | border | size(HEIGHT, EQUAL,
            // 10)
        });
    });

    screen.Loop(main_renderer);

    return 0;
}
