#include <cmath>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/node.hpp>
#include <string>

#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/loop.hpp"
#include "ftxui/component/screen_interactive.hpp"

#include "plot.hpp"

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


int main() {

    auto screen = ScreenInteractive::Fullscreen();

    // Create some data
    auto x = arange(0, 2 * M_PI, 0.01);
    std::vector<double> y(x.size());
    std::transform(x.begin(), x.end(), y.begin(), [](double v) { return std::sin(v); });

    std::string ymin_str;
    double ymin = -1.0;
    std::string ymax_str;
    double ymax = 1.0;

    auto ymin_inp = Input(InputOption{
	.content = &ymin_str,
	.multiline = false,
	.on_enter = [&]{
	    try {
		ymin = std::stod(ymin_str);
	    } catch (...) {}
	}
    });
    auto ymax_inp = Input(InputOption{
	.content = &ymax_str,
	.multiline = false,
	.on_enter = [&]{
	    try {
		ymax = std::stod(ymax_str);
	    } catch (...) {}
	}
    });

    // Create the plot component
    PlotOption op;
    op.x = x;
    op.y = y;
    op.xmin = 0.0;
    op.xmax = 2*M_PI;
    op.ymin = &ymin;
    op.ymax = &ymax;
    auto plot = Plot(op);

    // // Main container to define interactivity of components
    auto main_container = Container::Vertical({
	plot,
	ymin_inp,
	ymax_inp
    });

    // Main renderer to define visual layout of components and elements
    auto main_renderer = Renderer(main_container, [&] {
	return vbox({
	    plot->Render(),
	    hbox({
		ymin_inp->Render() | size(WIDTH, EQUAL, 10),
		separatorEmpty(),
		ymax_inp->Render() | size(WIDTH, EQUAL, 10),
	    }) | border,
	});
    });

    screen.Loop(main_renderer);

    return 0;
}
