# OneSignal-Embedded-SDK
This is an early stage open source C++ library for OneSignal, allowing you to send push notifications from microcontrollers like the ESP32 and ESP8266 (currently only these two MCUs are supported).

This library is in an early stage of development. 

TODO:
- Add tests and CI
- Expand support for more platforms like Arduino
- Use tests & lldb to verify there aren't any memory leaks
- Add error handling
- Add documentation

## Using the SDK

### Initializing the SDK
You can initialize the SDK with only your App ID, as long as you know exactly what user ID's you will be sending push notifications to. If you want to send to a broader audience however, such as a filter, you will need to provide your REST API key as well.

```cpp
// Initialize with only an App ID
OneSignal client("APP_ID_HERE");

// Or, initialize with a REST API key
OneSignal client("APP_ID_HERE", "REST_API_KEY_HERE");
```

Once you have initialized the SDK, you can construct and send notifications to audiences.

```cpp
OSNotification notification;
notification.title = "Hello, World!"
notification.subtitle = "Test";
```

Once you've constructed the notification, you will need to construct an audience to send it to. This can be as simple as initializing an audience with a single player ID, or you can also use segments.

```cpp
// Send notification to a single user
OSAudience audience("PLAYER_ID_HERE");

// Send to multiple player ID's
OSAudience audience({"player_id_1", "player_id_2"});

// Send to a broader audience
// Constructor can also accept an excluded_segments parameter
OSAudience audience({"include_audience_name_1"}, {"excluded_audience_name_1"});
```

Once you've constructed both the notification and the audience, you are ready to send the notification.

```cpp
OneSignal.sendNotificationToAudience(notification, audience);
```
