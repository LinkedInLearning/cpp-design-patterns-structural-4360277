#include <iostream>
#include <string>

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

int main()
{
    WorldWeatherAPI worldWeather;
    FreeWeather freeWeather;
    RealtimeWeatherService realtimeWeather;

    auto const location = "San Francisco, CA, US";
    // Call each API and combine the results
    tuple<float, float, string> worldWeatherResult = worldWeather.getWeather(location);
    tuple<float, string> freeWeatherResult = freeWeather.retrieve_weather(location);
    tuple<float, float, string> realtimeWeatherResult = realtimeWeather.weatherConditions(location);

    // Combine the results into a single string
    float temperature = get<0>(worldWeatherResult);
    float humidity = get<1>(realtimeWeatherResult);
    string shortDescription = get<1>(freeWeatherResult);

    cout << "\nWeather for " << location << endl
         << shortDescription << endl
         << "Temperature: " << temperature << " C" << endl
         << "Humidity: " << humidity << " %" << endl;

    return 0;
}
