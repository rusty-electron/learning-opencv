# Week 2:

 This week covers concepts of 1D and 2D filtering, correlation, convolution and edge issues.

 I have added MATLAB implementation of various concepts and will be adding opencv implementations soon.

 <hr>

*  Distinction between the two Sigmas
    * The sigma used in the generation of noise determines the spread of the values of noise for individual pixels i.e. the higher the value of sigma or standard deviation, the more will be the chances of having higher noises in the mix.

    * The sigma in case of gaussian filter generation, its value determines the extent of blurring of the image. The higher value of this sigma will blur the image more and thereby reduce the effect of the other sigma.

* Linearity: a system is said to be linear if these two functions hold

    * Additivity:
    * Multiplicative Scaling:

* Impulse Function:
    * In discrete terms, an impulse is just a function with the value of 1 at a single location.
    * In continuous systems, an impulse is an idealized function which is very thin but tall enough to have an area of 1 unit.

    i.e it has zero width but infinite height
* **Impulse Response**: Assume you have a black box `X` and you feed the system an impulse as input and get `h(x)` as the response then this response is known as impulse response.

    If the black box is `linear` then we can realize its function by using `h(x)`.

* **Convolution**:
    * Convolution and correlation filters provide same result for symmetric filters.
    * Convolving any matrix with the impulse function gives back the image.

    * Properties:
        * linear and shift invariant
        * commutative
        * associative
        * identity: impulse function
        * differentiation

* **Convoluton vs. Correlation**: To do!

* **Shift Invariants**: To do!

* **Reducing Computational complexity**: If we convolve a WxW filter with an NxN image, we need to perform N<sup>2</sup>W<sup>2</sup> multiplies. But it is possible to generate the same filter using the convolution of a row matrix R and a column matrix C both of length W. 

    <a href="https://www.codecogs.com/eqnedit.php?latex=G&space;=&space;H&space;*&space;F&space;=&space;(C&space;*&space;R)&space;*&space;F&space;=&space;C&space;*&space;(R&space;*&space;F)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?G&space;=&space;H&space;*&space;F&space;=&space;(C&space;*&space;R)&space;*&space;F&space;=&space;C&space;*&space;(R&space;*&space;F)" title="G = H * F = (C * R) * F = C * (R * F)" /></a>

    So We do two convolutions with WxNxN. So it is useful if W is big enough such that 

    <a href="https://www.codecogs.com/eqnedit.php?latex=2&space;\cdot&space;W&space;\cdot&space;N^2&space;<<&space;W^2&space;\cdot&space;N^2" target="_blank"><img src="https://latex.codecogs.com/gif.latex?2&space;\cdot&space;W&space;\cdot&space;N^2&space;<<&space;W^2&space;\cdot&space;N^2" title="2 \cdot W \cdot N^2 << W^2 \cdot N^2" /></a>

    > Fact: dividing by a constant is a linear operation as you may realize that dividing by `c` is the same as multiplying by `1/c`.

    
* For Solving Boundary Issues, MATLAB offers three output modes
    * full
    * same 
    * valid

* new MATLAB provides the following methods for boundary issues
     * clip filter(black) 
        ```matlab
        imfilter(f,g,0)
        ```
     * wrap-around
        ```matlab
        imfilter(f,g,'circular')
        ```
    * copy edge
        ```matlab
        imfilter(f,g,'replicate')
        ```
    * reflect across edge
        ```matlab
        imfilter(f,g,'symmetric')
        ```
        > *Reflective method* is the suitable solution for edge issues as it imitates the statistics of the color intensities of the rest of the image. Also this method doesn't allow obvious edge boundaries to be induced.

* Action of various linear filters on an image:

    > In case if the coefficients of the filters don't sum up to 1.0, a scale value can either be multiplied to the filter or the image *(not both)* for compensation.

    * **Impulse Filters - correlation**: If the impulse is centred in the filter, it returns the original image with no changes. In case of shifting the impulse by 1 pixel to the right, the output image is shifted by 1 pixel to the left w.r.t. the original image. 
    
    * **Simple uniform weighted filter**: a 3x3 filter with weights of 1/9 applied to an image will simple blur it.
    
    * **Sharpening Filter**:  *Duh!* I will write here about unsharp mask soon.

* **Salt and pepper noise**:
    It is also known as impulse noise. This noise is caused by sharp and sudden disturbances in the image signal. It presents itself as sparsely occurring white and black pixels.

* **Median Filter**:
    The effective noise reduction technique for salt and pepper noise is median filter.
    * It is a non-linear filter
    * It is edge preserving

    ```matlab
    %generating salt and pepper noise
    noisy_img = imnoise(img,'salt & pepper', d); %d is the noise intensity

    %applying median filter
    filtered = medfilt2(noisy_img);
    ```

