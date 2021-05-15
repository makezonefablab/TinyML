# TinyML

Arduino NANO 33 BLE로 TinyML을 실습하기 위한 코스입니다.


<img src="https://github.com/makezonefablab/TinyML/blob/main/imgs/9947DB485F93D2B10E.jpeg" width="750" title="아두이노 나노 33 BLE " alt="아두이노 나노 33 BLE "></img><br/>

<img src="https://github.com/makezonefablab/TinyML/blob/main/imgs/nano33ble.jpeg" title="아두이노 나노 33 BLE " alt="Parts"></img><br/>

<img src="https://github.com/makezonefablab/TinyML/blob/main/imgs/Nano-BLE-Sense-pinout.jpeg" width="750" title="아두이노 나노 33 BLE " alt="PinOut"></img><br/>

# Basic Contents
[Project I : Basic Course](https://github.com/makezonefablab/TinyML/tree/main/examples/01.Basic)
* [LED Blink]
  * 아두이노의 가장 기본적인 LED 깜빡임을 제어해 봅니다.
* [Blink Button]
  * 버튼의 누름에 따른 LED 깜빡인 제어를 해봅니다.
* [Servo]
  * 서보모터로 각도제어를 해봅니다.
* [DHT11]
  * 온습도 센서로부터 값을 측정해 봅니다.

<img src="https://github.com/makezonefablab/TinyML/blob/main/imgs/total_Schem_bb.png.ps.png" width="750" title="배선도 " alt="PinOut"></img><br/>

# tinyML Contents

[Project I : Gesture Recognition](https://github.com/makezonefablab/TinyML/tree/main/examples/1.Gesture%20Recognition/NANO33-ML)
* [Get Gyroscope Data]
  * The data of gyroscope is sent through serial port
  * 자이로스코프의 데이터를 시리얼포트를 통해 전송 받아봅니다.
* [Vibration Induction]
  * The LED lights up when movement is detected
  * 움직임이 감지되면 LED를 켜봅니다.
* [Directional Sensing]
  * LED lights indicate direction with different colors
  * LED 색으로 방향을 나태내 봅니다.
* [Get Training Data]
  * Collect 100 repeated operations of the same gesture, and when it reaches 100 times, the red light will be on. The green light will be on when the operations exceed 100 times, and the data in the format of CSV will be sent through the serial port
  * 같은 움직임을 100회 반복하여 그 데이터를 모아봅니다. 빨간색 LED가 켜진 동안에 데이터를 모으고 초록색 LED가 켜지면 100회를 넘은 것으로 표시할 수 있습니다. 해당 데이터들은 시리얼포트를 통해 CSV파일로 저장합니다.
* [Train Gesture Model]
  * Using jupyter notebook to train model
  * jupyter를 통해 데이터를 트레이닝합니다.
* [Predict Gesture]
  * Predict the gesture and send the two gesture possibilities through the serial port
  * 사용자의 움직임을 예측하고, 2개의 예측된 데이터의 가능값(possibilities)을 시리얼포트로 전송합니다.
* [Visualize Predict Gesture]
  * Predict the gesture and show the two gesture possibilities through web pages.
  * 사용자의 움직임을 예측하고, 웹페이지를 통해 직접 2개의 예측된 데이터의 가능값(possibilities)을 표시합니다.



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
