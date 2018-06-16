# Notes for Deep Learning by Andrew Ng  
### 1. What is Deep Learning?  
- What we will learn: 1. Neural Networks and Deep Learning 2. Improving Deep Neural Networks: Hyperparameter tuning, Regularization and Optimization 3. Structuring your Machine Learning project 4. Convolutional Neural Networks (CNN) 5. Natural Language Processing: Building sequence models (Recurrent Neural Networks and Long Short Term Memory)  

### 2. What is Neural Network  
- The simplest neural network, just one single neuron, giving a X and will have the correspoding Y. This classified line is called Rectified Linear Unit (ReLU), rectified means that the value is larger or equal to 0.  
![](figures/house-price.png) ![](figures/house-price-2.png)  

- More complicated one, we have these kinds of considerations and some of them will form a new consideration. Afterwards, these considerations will converage to the output.  
![](figures/house-price-3.png)  

- If we put four inputs (input features) and the combine whatever they want, the input is called `input layer` and the hidden layer is also called `dense connected layer` and the output is `output layer`. By giving many training sets including the input features and the corresponding output to this model to learn, the neural network will figure out the best function mapping x to y.  
- Supervised Learning: giving the x and the mapping y to this neural network.  

### 3. Supervised Learning with Neural Networks  
- Standard NN, CNN (image data), RNN (sequence data link speech recognition and NLP), Custom and hybrid NN.  
![](figures/supervise-learning.png)  

- Structured data and unstructure data. Structured data is more well defined.  
![](figures/data-type.png)  

### 4. Drivers Behind the Rise of Deep Learning  
- Why deep learning takes off? Digitalization everywhere right now, everyone can have access to smartphone, internet and digital products easily and it will bring a lot of data.  
![](figures/nn-take-off.png)  

- If we want to make our computation faster, it will definitely depend on the algorithm we applied. We can see that Sigmoid activation function, the two arrows indicate that the derivative or the gradient is nearly zero, which means it will take too much time to learn or adjust the parameters. However, if we use the ReLU, which we can find the right side, the gradient exits all the time ant not equal to zero, so the NN will be trained faster than Sigmoid.  
![](figures/cycle.png)  

### 5. Binary Classification in Deep Learning  
- Logistic regression is used for binary classification (yes or no/1 or 0). X is the n_x dimensional feature vector which is transformed fron pixels and Y is the output label 1 or 0.  
![](figures/binary-classification.png)  

- Input (x, y). If we have m training examples, we stack all the examples into the matrix X.  
![](figures/notation.png)  

### 6. Logistic Regression  
- Solve the classification 1 or 0.  P hat means the probability. The output for sigmoid function is from 0 to 1.  
![](figures/logistic-regression.png)  

### 7. Logistic Regression Cost Function  
- The goal is to want the i-th y hat which is predicted by NN to equal to the ground truth the i-th y label. Thus, whether they are equal or closed can be measured by `Loss function`. We dont usually use squared error for logistic regression, since it will cause the optimization non-convex which has multiple optima and gradient descent may not find the global optimum. Loss function is defined for a single training example, while `Cost funtion` which is the cost of the parameters can measure how we are doing on entire traning set to find parameters for `W` and `b` to minimize the cost.  
![](figures/cost-function.png)  

### 8. Gradient Descent  
- Want to find w, b that minimize the cost function `J(w,b)`. Convex function and non-convex function. Gradient descent will make the value of cost function decrease in the steepest downhill. Through many iterations, the value of cost function will converge to the global optimum.  
![](figures/gradient-descent.png)  

- The learning rate alpha indicates and controls how big a step is we take on each iteration of gradient descent. If the cost function has two or more parameters, we use `partial derivative`.  
![](figures/gradient-descent-2.png)  

### 9. Derivatives  
![](figures/derivative.png)  

### 10. Derivatives Examples  
![](figures/derivative-2.png)  

### 11. Computation Graph  
- Forward propagation is to compute the output of the neural network. Back propagation is to compute the gradients or derivatives.  
![](figures/computation-graph.png)  

### 12. Derivatives with a Computation Graph  
- The function is `J = 3 * (a + bc)`. <a href="https://www.codecogs.com/eqnedit.php?latex=\frac{dJ}{da}&space;=&space;\frac{dJ}{dv}&space;*&space;\frac{dv}{da}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\frac{dJ}{da}&space;=&space;\frac{dJ}{dv}&space;*&space;\frac{dv}{da}" title="\frac{dJ}{da} = \frac{dJ}{dv} * \frac{dv}{da}" /></a>. This is called `chain rule`. In code, we usually use `dvar` to represent the notation <a href="https://www.codecogs.com/eqnedit.php?latex=\frac{dFinalOutput}{dvar}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\frac{dFinalOutput}{dvar}" title="\frac{dFinalOutput}{dvar}" /></a>.  
![](figures/computing-derivative.png)  

### 13. Logistic Regression Derivatives  
- The reason why the derivative of sigmoid function is `a * (1-a)` can be seen in [website](http://kawahara.ca/how-to-compute-the-derivative-of-a-sigmoid-function-fully-worked-example). This picture only shows the logistic regression on one single example.  
![](figures/logistic-derivative.png)  

### 14. Gradient Descent on m Training Examples  
- Cost function is the average loss function for m examples. Also, gradient for each parameters w1, w2, w3 .... and b should be similar with cost function which is the average gradient for m examples. Vectorization will get rid of the loops, since the loops are less efficient.  
![](figures/logistic-regression-m-examples.png)  

### 15. Vectorization  
- Vectorize the data will save a lot of time than non-vectorized.  
![](figures/vectorization.png)  

![](figures/vectorization-1.png)  

### 16. More Vectorization Examples  
- The rule of thumb is to avoid the explicit for-loop and to take a look at the numpy built-in functions first.  
![](figures/more-vector.png)  

![](figures/more-vector-1.png)  

### 17. Vectorizing Logistic Regression  
- Even though the bias `b` here is a constant, when it is applied to this vectorization, it will expand into the `1xm` dimensional vector and this is called `broadcasting` in python.  
![](figures/vectorizing-logistic.png)  

### 18. Vectorizing Logistic Regression's Gradient Computation  
![](figures/vectorization-gradient.png)  

- If we want to do the iteration for many times, give a for loop.  
![](figures/vectorization-gradient-1.png)  

### 19. Broadcasting in Python  
- reshape(1,4) is redundant because the `cal` is already 1 by 4 matrix. `axis = 0` means the vertically
![](figures/broadcasting-code.png)  

![](figures/broadcasting-example.png)  
- Broadcasting: `(m,n)` matrix +-\*/ `(1,n) => (m,n)` or `(m,1) => (m,n)`.  

### 20. Python-Numpy  
- Do not use `rank 1 array`, other than `column vector` or `row vector`.  
![](figures/rank1-array.png)  

![](figures/rank1-array-1.png)  

