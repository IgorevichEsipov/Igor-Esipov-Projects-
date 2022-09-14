//Igor Esipov 
//April 24, 2020
//Forecast

import java.io.*;

public class Forecast {

// an attribute for the temperature

private double temperature;

//An attribute for the sky condition

private String skyCondition;

// An attribute for the chance of rain

private int chanceOfRain;

public Forecast()
{
temperature=72.0;
skyCondition ="clear";
chanceOfRain=0;
}

public Forecast(double temperature, String skyCondition, int chanceOfRain)
{
if(temperature<-100 || temperature>150)
this.temperature=72.0;
else
this.temperature = temperature;
if(skyCondition.equals(""))
this.skyCondition="clear";
else
this.skyCondition = skyCondition;
if(chanceOfRain<0 || chanceOfRain>100)
this.chanceOfRain=0;
else
this.chanceOfRain = chanceOfRain;
}

public String toString() {
return "Sky condition: "+skyCondition+" Rain probability: "+chanceOfRain+"% ";
}

public double getTemperature() {
return temperature;
}

public void setTemperature(double temperature) {
if(temperature<-100 || temperature>150)
this.temperature=72.0;
else
this.temperature = temperature;
}

public String getSkyCondition() {
return skyCondition;
}

public void setSkyCondition(String skyCondition) {
if(skyCondition.equals(""))
this.skyCondition="clear";
else
this.skyCondition = skyCondition;
}

public int getChanceOfRain() {
return chanceOfRain;
}

public void setChanceOfRain(int chanceOfRain) {
if(chanceOfRain<0 || chanceOfRain>100)
this.chanceOfRain=0;
else
this.chanceOfRain = chanceOfRain;
}

public double fahrenheitToCelsius()
{
double cel =(temperature-32)* 5/9;
return cel;
}

public double celsiusToFahrenheit()
{
double fah = (temperature * 9/5) + 32;
return fah;
}

public double fahrenheitToKalvin()
{
double kel = fahrenheitToCelsius()+273.15;
return kel;
}

public double kelvinToFahrenheit()
{
double fah = (temperature- 273.15) * 9/5 + 32;
return fah;
}


public boolean isRaining()
{
//Condition of chance of rain
if(chanceOfRain>80 && (skyCondition.equalsIgnoreCase("cloudy")))
return true;
else
return false;
}

public void print(String foreCastData) throws IOException {
//open file in append mode
PrintWriter printWriter = new PrintWriter(new FileWriter("forecast.txt",true));
//write the line to file using printWrite object
printWriter.println(foreCastData);
//close the stream
printWriter.close();
}
}

