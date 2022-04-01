public class Car
{
   String UserId;
   int Fuel;
   int CurrentSpeed;

  public Car(String UserId, int Fuel, int CurrentSpeed)
   {
       this.UserId=UserId;
       this.Fuel=Fuel;
       this.CurrentSpeed=CurrentSpeed;
   }

   public void ShowCarState()
   {
      double MaxGauge = 100;

      double PercentageFuel = Fuel / MaxGauge * 100;

      System.out.println("소유자 ID는 :" + UserId + "이고 연료량은 현재 몇"+PercentageFuel+"% 현재 속도는 "+ CurrentSpeed + "Km");
   }

   public void Accel()
   {
      int ACC_STEP = 10;
      int FUEL_STEP = 2;

      System.out.println("액셀 작동");
      if(Fuel==0)
         return;

      else
      {
         CurrentSpeed+=ACC_STEP;
         Fuel=Fuel-FUEL_STEP;
      }
   }

   public void Brake()
   {
      int BRK_STEP = 10;

      System.out.println("브레이크 작동");
      
      if(CurrentSpeed<10)
         CurrentSpeed=0;
      else
         CurrentSpeed-=BRK_STEP;
   }
  }
  
  
  public class RacingCar
{
   public static void main(String[] args)
   {
      Car myCar = new Car("driver", 10, 20);

      myCar.ShowCarState();
      myCar.Brake();
      myCar.Accel();
   }
}

//이클립스에서 메인 클래스를 찾을 수 없다는 오류 발생시 윈도우 region 설정에서 UTF-8 설정 해제
