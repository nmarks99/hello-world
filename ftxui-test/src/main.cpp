#include <ftxui/component/event.hpp>
#include <ftxui/dom/node.hpp>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/loop.hpp"

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
    return m*value + b;
}

int main() {

    // // sine wave
    // auto x = arange(0.0, 10*M_PI, 0.01);
    // std::vector<double> y(x.size());
    // std::transform(x.begin(), x.end(), y.begin(), [](double v){
	// return std::sin(v);
    // });

    // Line
    auto x = arange(0, 2*M_PI, 0.01);
    std::vector<double> y(x.size());
    std::transform(x.begin(), x.end(), y.begin(), [](double v){
	return std::sin(v);
    });

    auto xminmax = std::minmax_element(x.begin(), x.end());
    auto xmin = *xminmax.first;
    auto xmax = *xminmax.second;
    auto yminmax = std::minmax_element(y.begin(), y.end());
    auto ymin = *yminmax.first;
    auto ymax = *yminmax.second;

    std::vector<int> xnew;
    std::vector<int> ynew;
    auto make_data = [&](int w, int h) {
	xnew.clear();
	ynew.clear();
	for (size_t i = 0; i < x.size(); i++) {
	    auto xi = static_cast<int>(linear_map(x.at(i), xmin, xmax, 0, w));
	    auto yi = static_cast<int>(linear_map(y.at(i), ymin, ymax, 0+2, h-2));
	    xnew.push_back(xi+2);
	    ynew.push_back((h-2)-yi);
	}
    };

    auto screen = ScreenInteractive::Fullscreen();

    auto line_color = Color::Red;

    // locations in the canvas are given in (x,y) where x is 2 units wide
    // and y is four units wide. So if the screen is 100x100, a point can
    // be drawn at the center of the screen with DrawPointOn(200/2,400/2)
    auto plot_renderer = Renderer([&]{
	auto can = canvas([&] (Canvas &c) {
	    make_data(c.width(), c.height());
	    for (size_t i = 0; i < c.height(); i++) {
		if (i % 4 == 0) {
		    c.DrawText(0, i, "_ ");
		}
	    }
	    // for (size_t i = 0; i < c.width(); i++) {
		// if (i % 4 == 0) {
		    // c.DrawText(i, c.height()-2, "|");
		// }
	    // }
	    for (size_t i = 0; i < x.size(); i++) {
		c.DrawPoint(xnew.at(i), ynew.at(i), true, line_color);
	    }
	});
	return can | flex;
    });

    std::vector<std::string> color_ops = {"Red", "Green", "Blue", "White"};
    int color_op_ind = 0;
    DropdownOption dropdown_op;
    dropdown_op.radiobox.entries = &color_ops;
    dropdown_op.radiobox.selected = &color_op_ind;
    dropdown_op.radiobox.on_change = [&]{
	switch (color_op_ind) {
	    case 0:
		line_color = Color::Red;
		break;
	    case 1:
		line_color = Color::Green;
		break;
	    case 2:
		line_color = Color::Blue;
		break;
	    case 3:
		line_color = Color::White;
		break;
	}
    };
    auto color_inp = Dropdown(dropdown_op);

    // // Main container to define interactivity of components
    auto main_container = Container::Vertical({
	color_inp
    });

    // Main renderer to define visual layout of components and elements
    auto main_renderer = Renderer(main_container, [&]{
	return vbox({
	    plot_renderer->Render() | flex | border,
	    vbox({
		color_inp->Render() | size(WIDTH, EQUAL, 10),
	    }) | border | size(HEIGHT, EQUAL, 10),
	    // paragraph("Here is some text\nthat might\ntake up many lines?") | border | size(HEIGHT, EQUAL, 10)
	});
    });

    screen.Loop(main_renderer);

    return 0;
}
