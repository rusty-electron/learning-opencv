# Edge Detection: Gradients

## Edges

Here is an image of a house:

![](assets/cottage.png)

The given image consist of a small number of black pixels over a background of white. Even after having very less pixel information we can still identify it as a house. The black pixels are forming the edges of the building so it seems that *edges are important*.

## Origin of edges:

* Surface normal discontinuity
* Depth discontinuity
* Surface color discontinuity
* Illumination discontinuity

## Edge Detection

*Basic Idea:* Look for a neighbourhood with strong signs of change

* *Visualization*

Consider this image:

![](./assets/img.png)

We can plot this image as an 3-D plot to visualize the edges w.r.t sharp intensity change.

The 3-D plot when looked upon from the top appears just like the original image.

![](./assets/surf.png)

But, on rotating the 3-D plot we discover the sharp edges formed by the intensity changes.

![](./assets/surf-rot.png)
<hr>

An Edge is place of rapid change in the image intensity function.

Therefore, this rapid change will create a slope from one intensity state to another. We know that the derivative of a function at a point gives us the slope of the function at that point. So applying differentiation at an edge will give us peaks and the extrema of these peaks are the edges.

*Intensity variation at edges:*

![](./assets/intensity-variation-edge.png)

**Image Gradient:**

Differential Operators: when applied to an image returns some derivatives. These operators when applied as filters compute the `image gradient function`.

![](./assets/gradient.png)

*Direction of Gradient:*

![](./assets/gradient-direction.png)

*The gradient points in the direction of most rapid increase of intensity.*

![](./assets/formula.png)

The magnitude of the image gradient is zero when:

* The image is constant over the entire neighbourhood
* The function `f(x,y)` is at a maximum
* The function `f(x,y)` is at a minimum

**Discrete Gradient:**

![](./assets/2d-derv.png)

As continuous derivatives are not possible in programming, therefore we resort to calculating derivatives by `finite differences`.

![](./assets/finite-diff.png)

**Partial Derivative of an Image:**

Apply filter of `[-1 1]` to evaluate PD w.r.t x and apply `[-1; 1]` for PD w.r.t. y.

*Discrete Gradient:*

![](./assets/dis-grad.png)

*Sobel Operator:*

![](./assets/sobel.png)

This operation is able in MATLAB as the function `imgradientxy(image,'sobel')`. But you need to multiply it by 1/8 for *normalization*.

*Well-known Image Gradient Operators:*

![](./assets/well-known-gradient.png)

*Note:* Using *correlation* or *convolution*, the choice doesn't matter as long we know how to interpret the result. `imfilter` does correlation by default but if we want to perform convolution, we can do so by specifying the option as. Anyway, interpreting results of correlation is much easier.

```matlab
imfilter(A,h,'conv')
```
*Task:* Try the gradient angle finder to find regions with gradient angle of `180 deg or -180 deg`. 

**Applying in Real World:**

Simply applying gradient operation on real world images will not yield satisfactory results because real images don't have smooth distribution of pixel intensity as found in our sample shape images.

Here is an example of intensities along a row or column of an image.

![](./assets/intensity.png)

Applying derivative operator, we get:

![](./assets/intensity-derv.png)

The noises inherent in the image are the obstacles in detection of the edges. Like all other noises, this noise can be reduced by applying a proper filter.

![](./assets/noise-vs-gradient.png)

Therefore, in this example we first apply a gaussian filter to the image and then find the image gradient. The peaks in the image gradient matrix are the edges.   

![](./assets/filter-intensity.png)

Also, note that differentiation is associative and linear.

![](./assets/note.png)

Using this propery, we can simply find the derivative of the filter and then apply the result as filter to the image.

![](./assets/short-cut.png)

Another way to find the edges using derivatives is to evaluate the second derivative of the image.

![](./assets/2nd-derv.png)

The second derivative provides a smooth slope at the edge region.

## MATLAB Implementation Results

I coded the procedures mentioned above in MATLAB and found the given results.

At first, I used the simple discrete gradient operator `[0 0 0;-0.5 0 0.5; 0 0 0]` on a basic image with a shape of diamond on it to evaluate the partial derivative image along x-axis.

*Test Image:*

![](./test-results/img-basic.png)

*PD along x-axis:*

![](./test-results/img-basic-x.png)

*PD along y-axis:*

![](./test-results/img-basic-y.png)

*Edge Detection*

![](./test-results/img-basic-r.png)

Applying the same on a photograph of a scenery, we get:

![](./test-results/img_mont1.png)

* The Sobel operator and other well-known operators for calculating image gradients can be easily implemented in MATLAB using `imgradientxy()` function.

*The result of using Sobel operator on the previously used diamond image is shown below:*

![](./test-results/sobel.png)

<hr>

* Image gradient direction

*It is also possible to determine the gradient direction in an image using any of the already implemented image gradient operators*

*The example shown below is the output of a script that highlights the region of an image having gradient direction between 30 deg and 60 deg.*

![](./test-results/grad-dir.png)








