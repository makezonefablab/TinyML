# TinyML

Arduino NANO 33 BLE로 TinyML을 실습하기 위한 코스입니다.


# Content 目录

[Project I : Gesture Recognition](https://#)
* [Get Gyroscope Data]
  * The data of gyroscope is sent through serial port
* [Vibration Induction]
  * The LED lights up when movement is detected
* [Directional Sensing]
  * LED lights indicate direction with different colors
* [Get Training Data]
  * Collect 100 repeated operations of the same gesture, and when it reaches 100 times, the red light will be on. The green light will be on when the operations exceed 100 times, and the data in the format of CSV will be sent through the serial port
* [Train Gesture Model]
  * Using jupyter notebook to train model
* [Predict Gesture]
  * Predict the gesture and send the two gesture possibilities through the serial port
* [Visualize Predict Gesture]
  * Predict the gesture and show the two gesture possibilities through web pages.

[Project II : Open LED using Voice]
* [Audio Data Acquisition]
  * The data of microphone is sent through serial port
* [Record 2s Audio Data]
  * When it is turned on, the 2 second recording data of the microphone is sent through the serial port
* [Record Audio Data]
  * When on, recording data of microphone will be displayed on the web page
* [Get audio and visualize waveform]
  * Use Jupyter Notebook to get audio and visualize waveform
* [FFT Visualize Realtime]
  * Display real-time frequency domain data in web pages
* [Get Training Data]
  * Collect 100 repeated operations of the same voice, and when it reaches 100 times, the green light will be on. The blue light will be on when the operations exceed 100 times, and the data in the format of CSV will be sent through the serial port
* [Train Voice Model]
  * Using jupyter notebook to train model
* [Open LED using Voice]
  * Predict voice, switch LED light according to voice content

[Project III : Count rope jumping]
* [Get UART Data]
  * The data of UART is sent through serial port
* [Get Training Data]
  * Collect 100 repeated data of jumping actions, red light will be on when working, and when it reaches 100 times, the green light will be on. The data in the format of CSV will be sent through the serial port. Same as above, collect data of 100 ramdom actions.
* [Train Model]
  * Using jupyter notebook to train model
* [Predict Jumping]
  * Predict the jumping and send the possibility through the serial port
* [Count rope jumping]
  * Predict the rope-jumping action and show the count times through web pages.
