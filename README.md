# 4-Digit 7-Segment Display with Arduino

This project demonstrates how to interface a **4-digit 7-segment display** with an **Arduino** using the `SevSeg` library. It supports **numeric values** and **text mode (A-Z)** for limited character display.

---
## 🔌 Pinout Configuration
The 4-digit 7-segment display uses the following pin mapping:

![image](https://github.com/user-attachments/assets/44c27e0a-85dd-45b4-bf75-5f8f23b39fe9)


| Display Pin | Arduino Pin |
|------------|------------|
| D1         | D2         |
| D2         | D3         |
| D3         | D4         |
| D4         | D5         |
| a          | D6         |
| b          | D7         |
| c          | D8         |
| d          | D9         |
| e          | D10        |
| f          | D11        |
| g          | D12        |
| DP         | D13        |

---
## 🔢 Encoding Table
Since **7-segment displays** can only represent specific characters, the following encoding is used:

| Character | 7-Segment Binary (Common Cathode) |
|-----------|-----------------------------------|
| A         | `0b01110111` |
| B         | `0b01111111` |
| C         | `0b00111001` |
| D         | `0b00111111` |
| E         | `0b01111001` |
| F         | `0b01110001` |
| G         | `0b01101111` |
| H         | `0b01110110` |
| I         | `0b00000110` |
| J         | `0b00011110` |
| ...       | ... |

📌 **Note:** Some letters (M, W, K, X, Z) are approximated due to display limitations.

---
## 🔄 Switching Between Text and Value Mode
The display can be switched between **number mode** and **text mode** dynamically in the code.

### **🔢 Numeric Mode Example**
```cpp
sevseg.setNumber(1234, 0); // Display "1234"
```

### **🔠 Text Mode Example**
```cpp
displayText("HELP"); // Display "ABCD"
```

To define a function for **text display**, refer to the code provided in this repository.

---
## ⚡ Resistors for Safe Operation
Each **segment pin (D6 - D13)** should have a **330Ω resistor** in series to limit the current.

| Segment Pin | Resistor (Ω) |
|------------|--------------|
| a          | 330          |
| b          | 330          |
| c          | 330          |
| d          | 330          |
| e          | 330          |
| f          | 330          |
| g          | 330          |
| DP         | 330          |

Using resistors prevents **overcurrent** and extends the **lifespan** of the display.

---
## 🛠️ Installation
1. **Connect the 7-segment display** to the Arduino using the pinout above.
2. **Install the SevSeg Library** (if not installed):
   - Open Arduino IDE → Sketch → Include Library → Manage Libraries.
   - Search for `SevSeg` and install it.
3. **Upload the code** from this repository to your Arduino board.

---
## 📌 Notes
- The **SevSeg library** handles multiplexing automatically.
- **Brightness can be adjusted** using `sevseg.setBrightness(value);` (0-100).
- Some letters may not be displayed accurately due to **7-segment limitations**.

---
## 📜 License
This project is open-source and free to use under the **MIT License**.

📢 **Feel free to contribute, improve, and report any issues!** 🚀

