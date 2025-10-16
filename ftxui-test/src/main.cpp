#include <ftxui/component/event.hpp>
#include <ftxui/dom/node.hpp>
#include <string>
#include <cmath>
#include <iostream>

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

    // create a sine wave
    auto x = arange(0.0, 10*M_PI, 0.01);
    std::vector<double> y;
    for (const auto &v : x) {
	y.push_back(std::sin(v));
    }

    std::vector<int> xnew;
    std::vector<int> ynew;
    for (size_t i = 0; i < x.size(); i++) {
	auto xi = static_cast<int>(linear_map(x.at(i), 0, 10*M_PI, 0, 342));
	auto yi = static_cast<int>(linear_map(y.at(i), -1, 1, 0+5, 112-5));
	xnew.push_back(xi);
	ynew.push_back(yi);
    }

    auto screen = ScreenInteractive::Fullscreen();
    int screen_w = 0;
    int screen_h = 0;

    // locations in the canvas are given in (x,y) where x is 2 units wide
    // and y is four units wide. So if the screen is 100x100, a point can
    // be drawn at the center of the screen with DrawPointOn(200/2,400/2)
    auto plot_renderer = Renderer([&]{
	auto can = canvas([&] (Canvas &c) {
	    for (size_t i = 0; i < x.size(); i++) {
		c.DrawPoint(xnew.at(i), ynew.at(i), true, Color::Red);
	    }
	    // for (int i = 0; i < c.height()-1; i++) {
		// if (i % 4 == 0) {
		    // c.DrawText(0, i, std::to_string(i)+"-");
		// }
	    // }
	    c.DrawPointLine(1, 1, c.width(), 1, Color::Blue);
	    // c.DrawPointLine(0, c.height()-1, c.width(), c.height()-1, Color::Green);
	    // c.DrawPointLine(6, c.height()/2, c.width()/2, c.height()/2, Color::BlueViolet);
	});
	return can | flex;
    });

    // // Main container to define interactivity of components
    auto main_container = Container::Horizontal({});

    // Main renderer to define visual layout of components and elements
    auto main_renderer = Renderer(main_container, [&]{
	return vbox({
	    plot_renderer->Render() | flex | border,
	    paragraph("Here is some text\nthat might\ntake up many lines?") | border | size(HEIGHT, EQUAL, 10)
	});
    });

    screen.Loop(main_renderer);

    // Loop loop(&screen, main_renderer);
    // while(!loop.HasQuitted()) {
	// // dimx = screen.dimx();
	// // dimy = screen.dimy();
	// screen.PostEvent(Event::Custom);
	// loop.RunOnce();
	// std::this_thread::sleep_for(std::chrono::milliseconds(10));
    // }

    return 0;
}
