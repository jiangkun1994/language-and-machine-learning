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