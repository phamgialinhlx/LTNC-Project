# LTNC-Project
Phạm Gia Linh - UET  
20020203 - K65-C-CLC

## Introduction
Bài tập lớn - Game (môn học: Lập trình Nâng cao - INT2215 6)

## Getting Started

Ý tưởng cho bài tập lớn:
- Là một bản sao chép của game Chrome Dino (chrome://dino/)
- Làm hoàn hảo game
- Lấy bối cảnh là một sinh viên đang tạo ra một thế giới giữa truyện tranh và phim hoạt hình 

## Systems and Engine
Để chuẩn bị cho bài tập lớn, em cần chuẩn bị những kiến thức sau:
- Kiến thức nền tảng C++
- Kiến thức về con trỏ, map
- Kiến thức về OOP của C++
- Kiến thức để sử dụng thư viện SDL2
- Kiến thức về cách chia file
- Tài nguyên của game
Cách tổ chức game:
- Các class Wolf, character, Score, Particle, backGround kế thừa class gameObjects
- Vòng lặp trò chơi bắt đầu bằng việc nhận input, truyền input cho các hàm update của các gameObjects tại thời điểm đó để xử lý dữ liệu và cuối cùng là được render ra màn hình bằng class Graphics

## Rules
- Cách chơi y hệt game gốc: nhiệm vụ của người chơi là tránh các chướng ngại vật bằng cách bấm phím cách.

## Overview
- [Video](https://l.facebook.com/l.php?u=https%3A%2F%2Fyoutu.be%2FDIWSXSKCUtE%3Ffbclid%3DIwAR1WFvNjXk-2V_SopQpwaMiWsWRGXq3b9oneMfv48_N8uJt6anFXENhgAQo&h=AT1chO81EnZyn2_iTib9xP5QpP_Rww78_OlKGoFyvwgvOeMZeEAGOhUp39QtoLEkXAlyef4XgYtWHsj7A9QTSpKpoxXux_1zjxyeHJeurz18p_tAKRrPVd5Zjt1cIjGkdos9B2pBHKmn19KmyaY4tw)

## New Features
- Thêm menu
- Thêm hiệu ứng fade, flash
- Toàn bộ dồ họa được đổi cho phù hợp với bối cảnh game

## Notice
- Tài liệu tham khảo:
  - [Lazy Foo' Production](https://lazyfoo.net/tutorials/SDL/)
  - Các source code trên github nhưng chủ yếu là từ [source này](https://github.com/graysonpike/sdl-game) (một game bắn tàu)
  - Các video trên youtube (em xem một cách góp nhặt cần gì xem ý)

- Assets:
  - [Background Images](https://www.artstation.com/artwork/3d4DmJ) edited by me
  - [Ground/Mushroom Images](https://preview.redd.it/7dq6wk5oy4021.png?width=960&crop=smart&auto=webp&s=d33ed3b7d44d75942e86790c82f123496a32d6c4) edited by me
  - Menu, Character and Wolf Folder was redrawn from the movie and internet by my friend(ducmanh0911.work@gmail.com) and edited by me (some is designed by me)
  - Particle Folder designed and edited by me
 
- Music:
  - [Sunflower](https://www.youtube.com/watch?v=ApXoWvfEYVU)
  - [He's a Pirate](https://www.youtube.com/watch?v=yRh-dzrI4Z4)
