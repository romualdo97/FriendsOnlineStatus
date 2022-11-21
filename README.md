# FriendsOnlineStatus
UMG exercise to show the online status of a player friend list.

![showcase image](https://github.com/romualdo97/FriendsOnlineStatus/blob/master/Misc/showcase.png?raw=true)

Check showcase [video here](https://www.youtube.com/watch?v=dlhWOrYhwLg)

# Brief code description
- [Model](https://github.com/romualdo97/FriendsOnlineStatus/tree/master/Source/FriendsOnlineStatus/Public/Model): classes to represent player data.
- [View](https://github.com/romualdo97/FriendsOnlineStatus/tree/master/Source/FriendsOnlineStatus/Public/View): Unreal Widget classes representing distinct UI components.
- [Controller](https://github.com/romualdo97/FriendsOnlineStatus/tree/master/Source/FriendsOnlineStatus/Public/Controller): Classes to orchestrate the interaction between View and Model.
    - [Model Service](https://github.com/romualdo97/FriendsOnlineStatus/blob/master/Source/FriendsOnlineStatus/Public/Model/FriendsListService.h): Model gets wrapped in a service object that is passed to the controller, the single responsibility of the service object is to keep model data in-sync while providing an immutable interface to the underlying data and notifyies state changes.
    - [Widgets Provider](https://github.com/romualdo97/FriendsOnlineStatus/blob/master/Source/FriendsOnlineStatus/Public/Controller/Interfaces/FriendWidgetsProvider.h): Common and Shared widgets (Toast, Tooltip) are provided to the controller and other UI objects via a WidgetProvider object, in this code you'll find that the widget provider object is also the [GameInstance](https://github.com/romualdo97/FriendsOnlineStatus/blob/master/Source/FriendsOnlineStatus/Public/Game/FriendsOnlineStatusGameInstance.h), this aims to enforce separation of concerns between UI code, game code and business logic.

# Image credits:
<a href="https://www.flaticon.com/free-icons/circle" title="circle icons">Circle icons created by Freepik - Flaticon</a>