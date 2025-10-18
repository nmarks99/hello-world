#include <ftxui/component/event.hpp>
#include <ftxui/dom/node.hpp>
#include <string>

#include "ftxui/component/component_base.hpp"
#include "ftxui/component/loop.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include <cassert>

#include "plot.hpp"

double linear_map(double value, double a1, double a2, double b1, double b2) {
    if (a2 == a1) {
	return (b1 + b2) / 2;
    }
    const double m = (b2 - b1) / (a2 - a1);
    const double b = b1 - m * a1;
    return m * value + b;
}

namespace ftxui {

class PlotBase : public ComponentBase, public PlotOption {
  public:
    PlotBase(PlotOption option) : PlotOption(std::move(option)) {
        xout_.resize(x().size());
        yout_.resize(y().size());

	// auto-scale if limits are 0.0
	if (xmin() == scale_default_min || xmax() == scale_default_max) {
	    const auto xminmax = std::minmax_element(x().begin(), x().end());
	    xmin = *xminmax.first;
	    xmax = *xminmax.second;
	}
	if (ymin() == scale_default_min || ymax() == scale_default_max) {
	    const auto yminmax = std::minmax_element(y().begin(), y().end());
	    ymin = *yminmax.first;
	    ymax = *yminmax.second;
	}
    }

  private:

    Element OnRender() override {
        auto can = canvas([&](Canvas &c) {

            // draw y ticks
            for (size_t i = 0; i < c.height(); i++) {
                if (i % 4 == 0) {
                    c.DrawText(0, i, "_ ");
                }
            }

	    // draw x ticks
            for (size_t i = 0; i < c.width(); i++) {
                if (i % 4 == 0) {
                    c.DrawText(i, c.height()-2, "| ");
                }
            }

	    // TODO: this only needs to happen when something changes like
	    // data, canvas size, or axis limits
	    // remake integer data
	    std::transform(x().begin(), x().end(), xout_.begin(), [&](auto v) {
		return static_cast<int>(linear_map(v, xmin(), xmax(), 0, c.width()));
	    });
	    std::transform(y().begin(), y().end(), yout_.begin(), [&](auto v) {
		return -static_cast<int>(linear_map(v, ymin(), ymax(), 0, c.height() - 4)) + c.height() - 4;
	    });

            // // remake integer data for drawing only when canvas is resized
            // if (c.width() != canvas_width_last_ || c.height() != canvas_height_last_) {
                // std::transform(x().begin(), x().end(), xout_.begin(), [&](auto v) {
                    // return static_cast<int>(linear_map(v, xmin(), xmax(), 0, c.width()));
                // });
                // std::transform(y().begin(), y().end(), yout_.begin(), [&](auto v) {
                    // return -static_cast<int>(linear_map(v, ymin(), ymax(), 0, c.height() - 4)) + c.height() - 4;
                // });
            // }

            // draw line plot
            for (size_t i = 0; i < x().size(); i++) {
                c.DrawPoint(xout_.at(i), yout_.at(i), true, Color::Green);
            }

            canvas_width_last_ = c.width();
            canvas_height_last_ = c.height();
        });
        return can | flex;
    }
    std::vector<int> xout_, yout_;
    double canvas_width_last_ = 0;
    double canvas_height_last_ = 0;
};

Component Plot(PlotOption option) { return Make<PlotBase>(std::move(option)); }
} // namespace ftxui
