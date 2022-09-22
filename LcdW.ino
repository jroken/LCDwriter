#include <LiquidCrystal_I2C.h>

String data;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(9600); // Bandımızı seçtik Pythonda seçtiğimiz bant ile aynı olmasına dikkat edelim
  Serial.print("Program basladiii");

  lcd.begin();
  lcd.backlight(); // Lcd nin ışığını veriyoruz 
  //lcd.setCursor(0,0); //imleci 1.satır ilk karaktere getiriyoruz.
  //lcd.print("Burak <3"); //İlk satıra yazalım
  //lcd.setCursor(0,1); //imleci 2.satır ilk karaktere getiriyoruz.
  //lcd.print("AAAAAAAAAAAA"); /
  // Buradaki yorum satırları Lcdye proje haricindede başka nasıl kullanabileceğinizi anlatmakta
  //Bu Programın Çalışabilmesi İçin l2C LCD ekrana ihtiyacınız vardır
  //Python Dosyasını çalıştırdıktan sonra arduinonun bilgisayara takılı olduğuna dikkat edin
}



void loop() {
  
  
  while(Serial.available()) // Eğer Seri bağlantı mevcut ise sonsuz döngüye alıyoruz
  {
    
    data = Serial.read(); // Seri Bağlantı Yolu İle Gelen Verileri Okuyup data değişkenine veriyoruz
  
  }
  
  
  lcd.setCursor(0,0); // Lcd nin Ust Kısmı 
  
  // Alt Kısmını Kullanmak için
  // lcd.setCursor(0,1);
  // Olarak Değştirebilirsiniz
  
  lcd.print(data);
}
