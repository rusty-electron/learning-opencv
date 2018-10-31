# Hough Transform

Till now, we have only studied concepts related to traditional image processing, where we take an image function `I(x,y)` and after computation get the output of another output function `I'(x,y)`. **Hough transform** is one of the first computer vision technique that provides **intelligent** information from a given input of an image function `I(x,y)`.

Finding lines in a given image:

![](./img/intro.png)

Finding circles in a given image:

![](./img/circle-model.png)

Or any arbitrary shape:

![](./img/arbitrary.png)

## Related Terms

* Parametric Model: it can represent a class of instances where each is defined by a value of the parameters. For instance, lines, circles or even a parameterized template.

* Fitting a parametric model
    * Choose a parametric model to represent a set of features
    * Membership criterion is not local:
        it is not possible to tell if a point in the image belongs to a given model just by looking at that point

    * Computational complexity is vital

## Line Fitting

* Line fitting from Edge detection : Problems
    * Extra edge points(clutter), multiple models
    * only parts of line are detected (missing parts)
    * Noise in measured edge points

    ![](./img/difficult.png)

## Voting

Voting is a general technique where we let the features vote for all models that are compatible with it.

Algorithm:
    1. Cycle through features, each casting votes for model parameters.
    1. Look for model parameters that receive a lot of votes.

Why is works:

* Noise and clutter features cas votes too, but typically their votes should be inconsistent with the majority of **'good'** features.

* It is okay if some features are not observed, as model can span multiple fragments.

## Hough Transform

* Given points that belong to a line, what is the line?
* How many lines are there?
* Which points belong to which lines?

It is a `voting` technique that can be used to answer all of these.

Principle:

1. Each edge point votes for compatible lines.
1. Look for lines that get many votes. 

## Hough Space

* A line in an image corresponds to a point in Hough (parameter) space.

* A point in image space is a line in Hough space.

## Polar representation for lines

* Point in image space is now sinusoid segment in Hough space.

* write about restriction choices for `theta`.

## Hough transform algorithm

* Basic Hough transform algorithm

* Complexity of the Hough transform
    * Space complexity
    * Time complexity

