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

// class Plot : ComponentBase {
//
// };

int main() {

    auto screen = ScreenInteractive::Fullscreen();

    // auto x = arange(0, 2*M_PI, 0.01);
    // std::vector<double> y(x.size());
    // std::transform(x.begin(), x.end(), y.begin(), [](double v){
	// return std::sin(v);
    // });
//
    // auto xminmax = std::minmax_element(x.begin(), x.end());
    // auto xmin = *xminmax.first;
    // auto xmax = *xminmax.second;
    // auto yminmax = std::minmax_element(y.begin(), y.end());
    // auto ymin = *yminmax.first;
    // auto ymax = *yminmax.second;
//
    // std::vector<int> xnew;
    // std::vector<int> ynew;
    // auto make_data = [&](int w, int h) {
	// xnew.clear();
	// ynew.clear();
	// h -= 2;
	// for (size_t i = 0; i < x.size(); i++) {
	    // auto xi = static_cast<int>(linear_map(x.at(i), xmin, xmax, 0, w));
	    // auto yi = static_cast<int>(linear_map(y.at(i), ymin, ymax, 0, h));
	    // xnew.push_back(xi+2);
	    // ynew.push_back(-yi+h);
	// }
    // };


    std::array<Color, 5> test_colors = {Color::Red, Color::Blue, Color::Yellow, Color::Green, Color::Purple};
    std::vector<double> xtest = {0.0, 0.0, 0.0, 1.0, -1.0};
    std::vector<double> ytest = {1.0, -1.0, 0.0, 0.0, 0.0};

    auto line_color = Color::Red;


    std::string xmin_str = "-1.0";
    std::string xmax_str = "1.0";
    std::string ymin_str = "-1.0";
    std::string ymax_str = "1.0";

    // locations in the canvas are given in (x,y) where x is 2 units wide
    // and y is four units wide. So if the screen is 100x100, a point can
    // be drawn at the center of the screen with DrawPointOn(200/2,400/2)
    auto plot_renderer = Renderer([&]{
	auto can = canvas([&] (Canvas &c) {
	    // make_data(c.width(), c.height());

	    // draw y ticks
	    for (size_t i = 0; i < c.height(); i++) {
		if (i % 4 == 0) {
		    c.DrawText(0, i, "_ ");
		}
	    }
	    // // draw line plot
	    // for (size_t i = 0; i < x.size(); i++) {
		// c.DrawPoint(xnew.at(i), ynew.at(i), true, line_color);
	    // }

	    // test points
	    int xmin = std::stod(xmin_str);
	    int xmax = std::stod(xmax_str);
	    int ymin = std::stod(ymin_str);
	    int ymax = std::stod(ymax_str);
	    for (size_t i = 0; i < xtest.size(); i++) {
		auto xtest_i = linear_map(xtest.at(i), xmin, xmax, 0, c.width()-1);
		auto ytest_i = linear_map(ytest.at(i), ymin, ymax, 0, c.height()-2);
		ytest_i = -ytest_i + c.height()-2;
		c.DrawBlock(xtest_i, ytest_i, true, test_colors.at(i));
	    }
	});
	return can | flex;
    });


    auto xmin_inp = Input(&xmin_str);
    auto xmax_inp = Input(&xmax_str);
    auto ymin_inp = Input(&ymin_str);
    auto ymax_inp = Input(&ymax_str);

    // // Main container to define interactivity of components
    auto main_container = Container::Vertical({
	xmin_inp,
	xmax_inp,
	ymin_inp,
	ymax_inp,
    });

    // Main renderer to define visual layout of components and elements
    auto main_renderer = Renderer(main_container, [&]{
	return vbox({
	    plot_renderer->Render() | flex | border,
	    vbox({
		hbox({
		    text("X-Range: "),
		    xmin_inp->Render() | size(WIDTH, EQUAL, 10),
		    separatorEmpty(),
		    xmax_inp->Render() | size(WIDTH, EQUAL, 10)
		}),
		hbox({
		    text("Y-Range: "),
		    ymin_inp->Render() | size(WIDTH, EQUAL, 10),
		    separatorEmpty(),
		    ymax_inp->Render() | size(WIDTH, EQUAL, 10)
		}),
	    }) | border | size(HEIGHT, EQUAL, 10),
	    // paragraph("Here is some text\nthat might\ntake up many lines?") | border | size(HEIGHT, EQUAL, 10)
	});
    });

    screen.Loop(main_renderer);

    return 0;
}
