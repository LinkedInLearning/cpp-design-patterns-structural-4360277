#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class WorldWeatherAPI
{
public:
    tuple<float, float, string> getWeather(string location)
    {
        cout << "Calling worldWeather with location: " << location << endl;
        float temperature = 20.0f;
        float windSpeed = 5.5f;
        string shortDescription = "Sunny";
        return make_tuple(temperature, windSpeed, shortDescription);
    }
};

class FreeWeather
{
public:
    tuple<float, string> retrieve_weather(string location)
    {
        cout << "Calling freeWeather with location: " << location << endl;
        float temperature = 22.0f;
        string shortDescription = "Sunny";
        return make_tuple(temperature, shortDescription);
    }
};

class RealtimeWeatherService
{
public:
    tuple<float, float, string> weatherConditions(string location)
    {
        cout << "Calling realtimeWeather with location: " << location << endl;
        float temperature = 19.5f;
        float humidity = 60.0f;
        string shortDescription = "Partly cloudy with a chance of rain";
        return make_tuple(temperature, humidity, shortDescription);
    }
};

class WeatherFacade
{
public:
    WeatherFacade() : worldWeatherAPI(), freeWeather(), realtimeWeatherService() {}

    const string currentWeather(const string &location)
    {
        // Call each API
        tuple<float, float, string> worldWeatherResult = worldWeatherAPI.getWeather(location);
        tuple<float, string> freeWeatherResult = freeWeather.retrieve_weather(location);
        tuple<float, float, string> realtimeWeatherResult = realtimeWeatherService.weatherConditions(location);

        // Get relevant data from the results
        float temperature = get<0>(worldWeatherResult);
        float humidity = get<1>(realtimeWeatherResult);
        string shortDescription = get<1>(freeWeatherResult);

        stringstream result;

        result << "Weather for " << location << endl
               << shortDescription << endl
               << "Temperature: " << temperature << " C" << endl
               << "Humidity: " << humidity << " %" << endl;

        return result.str();
    }

private:
    WorldWeatherAPI worldWeatherAPI;
    FreeWeather freeWeather;
    RealtimeWeatherService realtimeWeatherService;
};

int main()
{
    WeatherFacade weatherFacade;

    auto const location = "San Francisco, CA, US";
    // Call each API and combine the results
    cout << weatherFacade.currentWeather(location) << endl;

    return 0;
}
