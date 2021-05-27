// The serviceUuid must match the serviceUuid of the device you would like to connect
// Copyright (c) 2018 p5ble
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

const serviceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
let myCharacteristic;
let input;
let myBLE;

let rSlider, gSlider, bSlider;

function setup() {

  createCanvas(300, 400);
  textSize(15);
  
  myBLE = new p5ble();

  // Create a 'Connect' button
  const connectButton = createButton('Connect')
  connectButton.mousePressed(connectToBle);
  connectButton.position(15, 65);

  // 슬라이더 생성하기
  gSlider = createSlider(0, 255, 0);
  gSlider.position(20, 100);

  // Create a 'Write' button
  const writeButton = createButton('Write');
  writeButton.position(gSlider.x + gSlider.width + 65, 130);
  writeButton.mousePressed(writeToBle);


}

function draw() {
  const g = gSlider.value();
  background(0, g, 0);
  fill(255);
  text(g, gSlider.x * 2 + gSlider.width+50, 35);
}

function connectToBle() {
  // Connect to a device by passing the service UUID
  myBLE.connect(serviceUuid, gotCharacteristics);
}

function gotCharacteristics(error, characteristics) {
  if (error) console.log('error: ', error);
  console.log('characteristics: ', characteristics);
  // Set the first characteristic as myCharacteristic
  myCharacteristic = characteristics[0];
}

function writeToBle() {
  const g = gSlider.value();
  // Write the value of the input to the myCharacteristic
  myBLE.write(myCharacteristic, g);
}
