import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QLabel, QSlider, QLineEdit

class SineWavePlotter(QWidget):
    def __init__(self):
        super().__init__()

        self.init_ui()

    def init_ui(self):
        # Create a Matplotlib figure and canvas
        self.fig, self.ax = plt.subplots()
        self.canvas = FigureCanvas(self.fig)

        # Create input boxes for amplitude, frequency, and scaling
        self.amplitude_label = QLabel('Amplitude:')
        self.amplitude_input = QLineEdit(self)
        self.amplitude_input.setText("1.0")

        self.frequency_label = QLabel('Frequency:')
        self.frequency_input = QLineEdit(self)
        self.frequency_input.setText("1.0")

        self.scaling_label = QLabel('Scaling:')
        self.scaling_input = QLineEdit(self)
        self.scaling_input.setText("1.0")

        # Create sliders for adjusting amplitude, frequency, and scaling
        self.amplitude_slider = QSlider(orientation=1)
        self.amplitude_slider.setMinimum(1)
        self.amplitude_slider.setMaximum(100)
        self.amplitude_slider.setValue(10)
        self.amplitude_slider.valueChanged.connect(self.update_amplitude)

        self.frequency_slider = QSlider(orientation=1)
        self.frequency_slider.setMinimum(1)
        self.frequency_slider.setMaximum(100)
        self.frequency_slider.setValue(10)
        self.frequency_slider.valueChanged.connect(self.update_frequency)

        self.scaling_slider = QSlider(orientation=1)
        self.scaling_slider.setMinimum(1)
        self.scaling_slider.setMaximum(100)
        self.scaling_slider.setValue(10)
        self.scaling_slider.valueChanged.connect(self.update_scaling)

        # Create layout
        layout = QVBoxLayout()
        layout.addWidget(self.amplitude_label)
        layout.addWidget(self.amplitude_input)
        layout.addWidget(self.amplitude_slider)
        layout.addWidget(self.frequency_label)
        layout.addWidget(self.frequency_input)
        layout.addWidget(self.frequency_slider)
        layout.addWidget(self.scaling_label)
        layout.addWidget(self.scaling_input)
        layout.addWidget(self.scaling_slider)
        layout.addWidget(self.canvas)

        self.setLayout(layout)

        self.amplitude = 1.0
        self.frequency = 1.0
        self.scaling = 1.0
        self.x = np.linspace(0, 2 * np.pi, 1000)
        self.line, = self.ax.plot(self.x, np.sin(self.x))

        self.timer = self.startTimer(50)  # Timer for animation

    def update_amplitude(self):
        self.amplitude = self.amplitude_slider.value() / 10.0
        self.amplitude_input.setText(str(self.amplitude))
        self.update_plot()

    def update_frequency(self):
        self.frequency = self.frequency_slider.value() / 10.0
        self.frequency_input.setText(str(self.frequency))
        self.update_plot()

    def update_scaling(self):
        self.scaling = self.scaling_slider.value() / 10.0
        self.scaling_input.setText(str(self.scaling))
        self.update_plot()

    def update_plot(self):
        y = self.amplitude * np.sin(self.frequency * self.x)
        self.line.set_ydata(y)
        self.ax.set_ylim([-self.scaling, self.scaling])
        self.canvas.draw()

    def timerEvent(self, event):
        # Timer event for animation
        self.x += 0.1
        y = self.amplitude * np.sin(self.frequency * self.x)
        self.line.set_ydata(y)
        self.ax.set_ylim([-self.scaling, self.scaling])
        self.canvas.draw()

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.init_ui()

    def init_ui(self):
        self.central_widget = SineWavePlotter()
        self.setCentralWidget(self.central_widget)

        self.setGeometry(100, 100, 800, 600)
        self.setWindowTitle('Sine Wave Animation')
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    sys.exit(app.exec_())

