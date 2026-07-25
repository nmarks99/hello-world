#include <iostream>
#include <memory>


class Circle {
  public:
    explicit Circle(double radius) : radius_{radius} {}
    double radius() const { return radius_; };
  private:
    double radius_;
};

class Square {
  public:
    explicit Square(double side) : side_{side} {}
    double side() const { return side_; };
  private:
    double side_;
};

namespace detail {

class ShapeConcept {
  public:
    virtual ~ShapeConcept() = default;
    virtual void draw() const = 0;
    virtual std::unique_ptr<ShapeConcept> clone() const = 0;
};

template <typename ShapeT, typename DrawStrategy>
class OwningShapeModel : public ShapeConcept {
  public:
    explicit OwningShapeModel(ShapeT shape, DrawStrategy drawer)
       : shape_{std::move(shape)}, drawer_{std::move(drawer)} {}

    void draw() const override { drawer_(shape_); }

    std::unique_ptr<ShapeConcept> clone() const override {
        return std::make_unique<OwningShapeModel>(*this);
    }

  private:
    ShapeT shape_;
    DrawStrategy drawer_;
};

}

class Shape {
  public:
    template <typename ShapeT, typename DrawStrategy>
    Shape(ShapeT shape, DrawStrategy drawer) {
        using Model = detail::OwningShapeModel<ShapeT, DrawStrategy>;
        pimpl_ = std::make_unique<Model>(std::move(shape), std::move(drawer));
    }

    Shape(Shape const& other) : pimpl_(other.pimpl_->clone()) {}

    Shape& operator=(Shape const& other) {
        // Copy-and-Swap Idiom
        Shape copy(other);
        pimpl_.swap(copy.pimpl_);
        return *this;
    }

    ~Shape() = default;
    Shape(Shape&&) = default;
    Shape& operator=(Shape&&) = default;

  private:
    std::unique_ptr<detail::ShapeConcept> pimpl_;

    friend void draw(Shape const& shape) {
        shape.pimpl_->draw();
    }
};



int main() {

    Circle circle1 {3.14};
    Circle circle2 {6.28};

    auto circle_drawer = [](Circle const& c) {
        std::cout << "Drawing Circle of radius " << c.radius() << std::endl;
    };

    Shape s1(circle1, circle_drawer);
    Shape s2(circle2, circle_drawer);

    draw(s1);
    draw(s2);

    Shape s3(s1);
    draw(s3);

    return EXIT_SUCCESS;
}
