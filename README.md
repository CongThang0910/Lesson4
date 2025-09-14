 STM32 Timer Example - LED Blinking

 Mô tả
Dự án này minh họa cách cấu hình **Timer cơ bản** trên vi điều khiển STM32 để:
- Tạo hàm Delay có độ chính xác cao.
- Cấu hình Timer tạo ngắt định kỳ mỗi 500ms.
- Trong ISR của Timer, đảo trạng thái của LED LD2 → kết quả LED nhấp nháy với chu kỳ 1000ms.

Ngoài ra, có thể sử dụng máy hiện sóng hoặc Logic Analyzer để kiểm tra độ chính xác của tín hiệu do Timer tạo ra.

---

Yêu cầu phần cứng
- STM32F103C8T6 (hoặc board STM32 có LED LD2).
- ST-Link để nạp chương trình.
- (Tuỳ chọn) Logic Analyzer hoặc Oscilloscope để kiểm tra tín hiệu.



Cấu hình Timer
- Timer: TIM2 (có thể thay đổi tuỳ chip).
- Tần số System Clock: 72 MHz.
- Ngắt Timer: mỗi 500ms.
- Trong hàm ngắt: đảo trạng thái LED LD2.



Cách chạy
1. Nạp chương trình vào STM32.
2. Quan sát LED LD2 sẽ nhấp nháy với chu kỳ 1 giây.
3. Dùng Logic Analyzer để kiểm tra độ chính xác của Timer.

---

