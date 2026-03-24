
# ☁️ Realistic Cloud Animation (OpenGL + GLUT)

A simple yet visually pleasing cloud animation built using **OpenGL** and **GLUT**, featuring smooth motion and a soft gradient sky.

---

## 🎥 Preview

<p align="center">
  <img src="C:\Users\asus\Downloads\WhatsApp Image 2026-03-24 at 11.40.12 AM.jpeg" alt="Cloud Animation Preview" width="600"/>
</p>

---

## ✨ Features

🌤️ **Dynamic Clouds**
- 5 independently moving clouds  
- Different speeds for natural variation  

🎨 **Beautiful Sky**
- Smooth gradient background  
- Soft color transitions for realism  

⚡ **Smooth Animation**
- ~60 FPS rendering  
- Seamless cloud looping  

---

## 🧠 How It Works

- Clouds are created using multiple overlapping circles for a fluffy effect  
- Each cloud has:
  - Unique position  
  - Individual speed  
- A timer function updates positions continuously to simulate motion  

---

## 🛠️ Requirements

- OpenGL  
- GLUT / FreeGLUT  
- C++ Compiler (g++ recommended)

---

## 🚀 Run the Project

### 🐧 Linux

```bash
g++ main.cpp -o cloud -lGL -lGLU -lglut
./cloud
```

### 🪟 Windows

```bash
g++ main.cpp -o cloud -lopengl32 -lglu32 -lfreeglut
cloud.exe
```

---

## 📂 Project Structure

```
📁 Realistic-Cloud-Animation
 ┣ 📄 main.cpp
 ┣ 🖼️ preview.png
 ┗ 📄 README.md
```

---

## 🎯 Future Improvements

- 🌅 Add sunrise/sunset transitions  
- 🌧️ Weather effects (rain, thunder)  
- 🌙 Day & night cycle  
- 🐦 Birds or moving elements  

---

## 🤝 Contributing

Feel free to fork this project and improve it. Contributions are always welcome!

---

## 📜 License

This project is open-source and free to use.

---

## ⭐ Support

If you like this project, give it a **star ⭐** — it really helps!
