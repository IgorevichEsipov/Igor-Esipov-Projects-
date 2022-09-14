//Igor Esipov 
//April 24, 2020
//Main 

import java.io.IOException;

public class Main{
public static void main(String[] args) throws IOException {
	
// 4 sets of forecasts printed
	
Forecast forecast1 = new Forecast(50,"Cloudy",20);
double f = forecast1.fahrenheitToCelsius();
String result=forecast1+"\n"+ String.valueOf(f)+"\u00B0"+"C "+" Is Raining: "+forecast1.isRaining();
forecast1.print(result);

Forecast forecast2 = new Forecast(80,"Cloudy",90);
double f1 = forecast2.fahrenheitToKalvin();
String result1=forecast2+"\n"+ String.valueOf(String.format("%.2f",f1))+"\u00B0"+"K "+" Is Raining: "+forecast2.isRaining();
forecast2.print(result1);

Forecast forecast3 = new Forecast(120,"Cloudy",70);
double f2 = forecast3.kalvinToFahrenheit();
String result2=forecast3+"\n"+ String.valueOf(String.format("%.2f",f2))+"\u00B0"+"F "+" Is Raining: "+forecast3.isRaining();
forecast3.print(result2);

Forecast forecast4 = new Forecast(40,"Clear",70);
double f3 = forecast4.celsiusToFahrenheit();
String result3=forecast4+"\n"+ String.valueOf(String.format("%.2f",f3))+"\u00B0"+"F "+" Is Raining: "+forecast4.isRaining();
forecast4.print(result3);

}
}

