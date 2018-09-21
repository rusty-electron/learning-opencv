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

An Edge is place of rapid change in the image intensity function.

Therefore, this rapid change will create a slope from one intensity state to another. We know that the derivative of a function at a point gives us the slope of the function at that point. So applying differentiation at an edge will give us peaks and the extrema of these peaks are the edges.

**Note:**

The magnitude of the image gradient is zero when:

* The image is constant over the entire neighbourhood
* The function `f(x,y)` is at a maximum
* The function `f(x,y)` is at a minimum

**Note:**

As continuous derivatives are not possible in programming, therefore we resort to calculating derivatives by `finite differences`.

