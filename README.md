# BlackBerry-Dynamics-Cordova-Plugins
This repository contains following Cordova plugins separated into branches:
 - `capacitor-base` branch corresponds to [capacitor-plugin-bbd-base](https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins/tree/capacitor-base) plugin
  - `file` branch corresponds to [cordova-plugin-bbd-file](https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins/tree/file) plugin
 - `file-transfer` branch corresponds to [cordova-plugin-bbd-file-transfer](https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins/tree/file-transfer) plugin
 - `sqlite-storage` branch corresponds to [cordova-plugin-bbd-sqlite-storage](https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins/tree/sqlite-storage) plugin
 - `inappbrowser` branch corresponds to [cordova-plugin-bbd-inappbrowser](https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins/tree/inappbrowser) plugin
 - `media-capture` branch corresponds to [cordova-plugin-bbd-media-capture](https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins/tree/media-capture) plugin

> Please visit appropriate branch in order to take a look at implementation of specific plugin.

## capacitor-plugin-bbd-base
`capacitor-plugin-bbd-base` plugin adds all needed configurations to be able to use `BlackBerry Dynamics` in your Ionic Capacitor application.
### Installation
```
$ npm i git+https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins#capacitor-base
```
### Uninstallation
```
$ npm uninstall capacitor-plugin-bbd-base
```

## cordova-plugin-bbd-file
`cordova-plugin-bbd-file` is a fork of [cordova-plugin-file@6.0.1](https://github.com/apache/cordova-plugin-file).
This plugin enables you to manage the FileSystem residing within the BlackBerry Dynamics secure container using a similar JavaScript API to the original plugin.
### Installation
```
$ cordova plugin add git+https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins#file
```
### Uninstallation
```
$ cordova plugin rm cordova-plugin-bbd-file
```

## cordova-plugin-bbd-file-transfer
`cordova-plugin-bbd-file-transfer` is a fork of [cordova-plugin-file-transfer@1.7.2](https://github.com/apache/cordova-plugin-file-transfer).
This plugin enables you to securely upload and download files within the BlackBerry Dynamics secure container using a similar JavaScript API to the original plugin.
### Installation
```
$ cordova plugin add git+https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins#file-transfer
```
### Uninstallation
```
$ cordova plugin rm cordova-plugin-bbd-file-transfer
```

## cordova-plugin-bbd-sqlite-storage
`cordova-plugin-bbd-sqlite-storage` is a fork of [cordova-plugin-sqlite-storage@4.0.0](https://github.com/litehelpers/Cordova-sqlite-storage).
This plugin enables you to securely create and manage an SQLite database within the BlackBerry Dynamics secure container using a similar JavaScript SQLite API to the original plugin.
### Installation
```
$ cordova plugin add git+https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins#sqlite-storage
```
### Uninstallation
```
$ cordova plugin rm cordova-plugin-bbd-sqlite-storage
```

## cordova-plugin-bbd-inappbrowser
`cordova-plugin-bbd-inappbrowser` is a fork of [cordova-plugin-inappbrowser@5.0.0](https://github.com/apache/cordova-plugin-inappbrowser/tree/5.0.x).
This plugin enables you to securely load helpful articles, videos, and web resources inside of your app without leaving your app.
### Installation
```
$ cordova plugin add git+https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins#inappbrowser
```
### Uninstallation
```
$ cordova plugin rm cordova-plugin-bbd-inappbrowser
```

## cordova-plugin-bbd-media-capture
`cordova-plugin-bbd-media-capture` is a fork of [of cordova-plugin-media-capture@3.0.4-dev](https://github.com/apache/cordova-plugin-media-capture).
This plugin enables you to capture audio, video and images using device's microphone or camera and store them within the BlackBerry Dynamics secure container using a similar JavaScript API to the original plugin.
### Installation
```
$ cordova plugin add git+https://github.com/blackberry/BlackBerry-Dynamics-Cordova-Plugins#media-capture
```
### Uninstallation
```
$ cordova plugin rm cordova-plugin-bbd-media-capture
```