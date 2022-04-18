package main
import "github.com/Arafatk/glot"
 
func main() {
    dimensions := 2
    persist := false
    debug := false
    plot, _ := glot.NewPlot(dimensions, persist, debug)
    pointGroupName := "Simple Circles"
    style := "circle"
    points := [][]float64{{7, 3, 13, 5.6, 11.1}, {12, 13, 11, 1,  7}}
        plot.AddPointGroup(pointGroupName, style, points)
    plot.SetTitle("Example Plot")
    plot.SetXLabel("X-Axis")
    plot.SetYLabel("Y-Axis")
    plot.SetXrange(-2, 18)
    plot.SetYrange(-2, 18)
    plot.SavePlot("2.png")
}

