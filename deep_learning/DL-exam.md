## Lecture 0  
- **Deep Learning** coupled to the application, **Machine Learning** application independent.  

## Lecture 1  
- **Feed forward** means forward propagation.  
- **Multi-layerd perceptron** means a neural network with many layers and it can generally approximate any function.  
- Why called feed forward? No recurrent connections among the neurons in network.  
- Why called network? The neurons are connected and they have **chain** relations.  
- When the cost function not converged:  
    - Present a training sample.  
    - Compare the results.  
    - Update the weights.  
- What is the gradient? Vector of all partial derivatives.  
- How to compute the loss of all samples? Calculate the sum of loss function for each training example, then get a mean of this sum.
- **Stochastic Gradient Descent (SGD)** is an approximation of the gradient from a small number of samples. (Compute the cost function for a small number of samples)  
- How could you extend the neural network into the non-linear function? Apply non-linear transformation.  
    - Generic kernel function (activation function)  
    - Designing feature extractors (convolution)  
    - Learn it (derive suitable parameters by learning the representations (features))  

## Lecture 2  
- Minimize KL divergence <=> minimize negative log likelihood <=> minimize cross-entropy <=> maximize maximum likelihood.  
- Usually: cross-entropy between data distribution and model distribution.  
- Output units determine the form of the cross-entropy function.  
- For the **binary classification**, no loss defined, but what happens to the gradients outside interval [0,1]? No more gradients, cannot be optimized by gradient descent.  
- How to binarize to two classes? Threshold predictions at y = 1/2.  

## Lecture 3  
- How does "1-d" change for a multi-layer network? One unique coordinate for each weight/bias in all the layers.  
- How to get cost gradient from training samples? Average dL/dw for loss L over all training samples.  

## Lecture 4  
- How to get rid of noisy pixels? Simple solution: replace the pixel by neibourhood average.  
- Representaion learning  
    - Kernel weights are feature detectors.  
    - Learning weights = Learning features.  
    - Convnet learns the feature representation.  
- What is the difference between convolution and matrix multiplication? Convolution can be written as a matrix multiplication.  
- What are three things to notice about this matrix?  
    - Sparse (many zeros)
    - Local (non-zero values occur next to each other)
    - Repeating values (same values repeat)
- What is the relation between feed-forward and convolutional networks? CNN is -by design- a limited version of feed forward.
- In terms of parameters, what is the advantage of convolution over matrix multiplication?  
    - Less parameters to learn. (Sparse (many zeros) and the non-zero values are repeating)
- Wait.. Less parameters is less flexibility. Why is this a good thing? Curse of dimensionality; each parameter has to be learned from data.
- If the input shifts to the left, the output shifts to the left (equivariance).
- **Max Pooling** is approximately invariant to local translations.
- For varying input size n; how to get a fixed size output m? Adapt pool width depending on input size: n/m  

## Lecture 5  
- If LR (learning rate) too high it will never find a good instantiation.  
- If LR too low it will take very long to find a good instantiation.  
- SGD is noisy, also close to a good place.
- How to take smaller steps? A: Reduce the LR over time (decay).  
- Useful algorithms to reduce the noise:  
    - Momentum: On average in the good direction (first moment)
    - RMSprop: Variance in the wrong direction is high (second moment)
    - Adam: Combines momentum and RMSprop (both moments)
- Momentum smooths the average of noisy gradients with EWMA
- RMSprop smooths the variance of noisy gradients with EWMA
- Adam combines momentum with RMSprop
- Effect of feature normalization on optimization: Circle has equal dimension contributions
- How to normalize all those features? Apply normalization also for each hidden layer.
- Batch norm: Normalize learned features.  

## Lecture 6  
- Beating overfitting  
    - Use more data! Data augmentation
    - Reduce the number of features
    - Reduce the complexity/flexibility of the model
- Noise Robustness
    - Not only variations in input data, also noisy variations of the weights and outputs
    - Noise added to input can be considered data augmentation
    - Noise added to weights encourages stability of the model
    - Noise with infinitesimal variance is equivalent to… weight norm regularisation
    - Noise added to the output means label smoothing

## Lecture 8  
- Size of the hidden (bottleneck) layer  
    - h < x, undercomplete layer, compress the input, compress well for training samples
    - h > x, overcomplete hidden layer, no compression needed (could just copy the input), useful for representation learning
    - What could prevent copying the input? Regularization

## Paper 1  
- Learning = Representation + Evaluation + Optimization  
- The fundamental goal of machine learning is to generalize the examples beyond the examples in the training set  
- In fact, a local optimum returned by simple greedy search may be better than the global optimum
- One way to understand overfitting is by decomposing generalization error into bias and variance
- Similar reasoning applies to the choice of optimization method: beam search has lower bias than greedy search, but higher variance, because it tries more hypotheses. Thus, contrary to intuition, a more powerful learner is not necessarily better than a less powerful one.
- strong false assumptions can be better than weak true ones, because a learner with the latter needs more data to avoid overfitting.
- Cross-validation, regularization term to the evaluation function can help to combat overfitting
