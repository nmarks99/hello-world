
## Error function for gradient descent
$$
Error_{(m,b)} = \frac{1}{N} \sum_{i=1}^{N} (y_i - (mx_i + b))^2
$$

## Partial derivatives of b and m for gradient descent 

$$
\frac{\partial}{\partial m} = \frac{2}{N} \sum_{i=1}^{N} - x_i(y_i - (mx_i+b))
$$

$$
\frac{\partial}{\partial b} = \frac{2}{N} \sum_{i=1}^{N} -(y_i - (mx_i+b))
$$