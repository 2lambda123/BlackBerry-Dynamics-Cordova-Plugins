/*
 Copyright (c) 2021 BlackBerry Limited. All Rights Reserved.
 Some modifications to the original Cordova File plugin
 from https://github.com/apache/cordova-plugin-file/
 
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>

extern NSString* const kCDVAssetsLibraryPrefixBD;
extern NSString* const kCDVFilesystemURLPrefixBD;

enum CDVFileErrorBD {
    NO_ERROR = 0,
    NOT_FOUND_ERR = 1,
    SECURITY_ERR = 2,
    ABORT_ERR = 3,
    NOT_READABLE_ERR = 4,
    ENCODING_ERR = 5,
    NO_MODIFICATION_ALLOWED_ERR = 6,
    INVALID_STATE_ERR = 7,
    SYNTAX_ERR = 8,
    INVALID_MODIFICATION_ERR = 9,
    QUOTA_EXCEEDED_ERR = 10,
    TYPE_MISMATCH_ERR = 11,
    PATH_EXISTS_ERR = 12
};
typedef int CDVFileErrorBD;

@interface CDVFilesystemURLBD : NSObject  {
    NSURL *_url;
    NSString *_fileSystemName;
    NSString *_fullPath;
}

- (id) initWithString:(NSString*)strURL;
- (id) initWithURL:(NSURL*)URL;
+ (CDVFilesystemURLBD *)fileSystemURLWithString:(NSString *)strURL;
+ (CDVFilesystemURLBD *)fileSystemURLWithURL:(NSURL *)URL;

- (NSString *)absoluteURL;

@property (atomic) NSURL *url;
@property (atomic) NSString *fileSystemName;
@property (atomic) NSString *fullPath;

@end

@interface CDVFilesystemURLProtocolBD : NSURLProtocol
@end

@protocol CDVFileSystemBD
- (CDVPluginResult *)entryForLocalURI:(CDVFilesystemURLBD *)url;
- (CDVPluginResult *)getFileForURL:(CDVFilesystemURLBD *)baseURI requestedPath:(NSString *)requestedPath options:(NSDictionary *)options;
- (CDVPluginResult *)getParentForURL:(CDVFilesystemURLBD *)localURI;
- (CDVPluginResult *)setMetadataForURL:(CDVFilesystemURLBD *)localURI withObject:(NSDictionary *)options;
- (CDVPluginResult *)removeFileAtURL:(CDVFilesystemURLBD *)localURI;
- (CDVPluginResult *)recursiveRemoveFileAtURL:(CDVFilesystemURLBD *)localURI;
- (CDVPluginResult *)readEntriesAtURL:(CDVFilesystemURLBD *)localURI;
- (CDVPluginResult *)truncateFileAtURL:(CDVFilesystemURLBD *)localURI atPosition:(unsigned long long)pos;
- (CDVPluginResult *)writeToFileAtURL:(CDVFilesystemURLBD *)localURL withData:(NSData*)encData append:(BOOL)shouldAppend;
- (void)copyFileToURL:(CDVFilesystemURLBD *)destURL withName:(NSString *)newName fromFileSystem:(NSObject<CDVFileSystemBD> *)srcFs atURL:(CDVFilesystemURLBD *)srcURL copy:(BOOL)bCopy callback:(void (^)(CDVPluginResult *))callback;
- (void)readFileAtURL:(CDVFilesystemURLBD *)localURL start:(NSInteger)start end:(NSInteger)end callback:(void (^)(NSData*, NSString* mimeType, CDVFileErrorBD))callback;
- (void)getFileMetadataForURL:(CDVFilesystemURLBD *)localURL callback:(void (^)(CDVPluginResult *))callback;

- (NSDictionary *)makeEntryForLocalURL:(CDVFilesystemURLBD *)url;
- (NSDictionary*)makeEntryForPath:(NSString*)fullPath isDirectory:(BOOL)isDir;

@property (nonatomic,strong) NSString *name;
@property (nonatomic, copy) NSURL*(^urlTransformer)(NSURL*);

@optional
- (NSString *)filesystemPathForURL:(CDVFilesystemURLBD *)localURI;
- (CDVFilesystemURLBD *)URLforFilesystemPath:(NSString *)path;

@end

@interface CDVFileBD : CDVPlugin {
    NSString* rootDocsPath;
    NSString* appDocsPath;
    NSString* appLibraryPath;
    NSString* appTempPath;

    NSMutableArray* fileSystems_;
    BOOL userHasAllowed;
}

- (NSNumber*)checkFreeDiskSpace:(NSString*)appPath;
- (NSDictionary*)makeEntryForPath:(NSString*)fullPath fileSystemName:(NSString *)fsName isDirectory:(BOOL)isDir;
- (NSDictionary *)makeEntryForURL:(NSURL *)URL;
- (CDVFilesystemURLBD *)fileSystemURLforLocalPath:(NSString *)localPath;

- (NSObject<CDVFileSystemBD> *)filesystemForURL:(CDVFilesystemURLBD *)localURL;

/* Native Registration API */
- (void)registerFilesystem:(NSObject<CDVFileSystemBD> *)fs;
- (NSObject<CDVFileSystemBD> *)fileSystemByName:(NSString *)fsName;

/* Exec API */
- (void)requestFileSystem:(CDVInvokedUrlCommand*)command;
- (void)resolveLocalFileSystemURI:(CDVInvokedUrlCommand*)command;
- (void)getDirectory:(CDVInvokedUrlCommand*)command;
- (void)getFile:(CDVInvokedUrlCommand*)command;
- (void)getParent:(CDVInvokedUrlCommand*)command;
- (void)removeRecursively:(CDVInvokedUrlCommand*)command;
- (void)remove:(CDVInvokedUrlCommand*)command;
- (void)copyTo:(CDVInvokedUrlCommand*)command;
- (void)moveTo:(CDVInvokedUrlCommand*)command;
- (void)getFileMetadata:(CDVInvokedUrlCommand*)command;
- (void)readEntries:(CDVInvokedUrlCommand*)command;
- (void)readAsText:(CDVInvokedUrlCommand*)command;
- (void)readAsDataURL:(CDVInvokedUrlCommand*)command;
- (void)readAsArrayBuffer:(CDVInvokedUrlCommand*)command;
- (void)write:(CDVInvokedUrlCommand*)command;
- (void)testFileExists:(CDVInvokedUrlCommand*)command;
- (void)testDirectoryExists:(CDVInvokedUrlCommand*)command;
- (void)getFreeDiskSpace:(CDVInvokedUrlCommand*)command;
- (void)truncate:(CDVInvokedUrlCommand*)command;
- (void)doCopyMove:(CDVInvokedUrlCommand*)command isCopy:(BOOL)bCopy;
- (void)uploadLogs:(CDVInvokedUrlCommand*)command;

/* Compatibilty with older File API */
- (NSString*)getMimeTypeFromPath:(NSString*)fullPath;
- (NSDictionary *)getDirectoryEntry:(NSString *)target isDirectory:(BOOL)bDirRequest;

/* Conversion between filesystem paths and URLs */
- (NSString *)filesystemPathForURL:(CDVFilesystemURLBD *)URL;

/* Internal methods for testing */
- (void)_getLocalFilesystemPath:(CDVInvokedUrlCommand*)command;

@property (nonatomic, strong) NSString* rootDocsPath;
@property (nonatomic, strong) NSString* appDocsPath;
@property (nonatomic, strong) NSString* appLibraryPath;
@property (nonatomic, strong) NSString* appTempPath;
@property (nonatomic, strong) NSString* persistentPath;
@property (nonatomic, strong) NSString* temporaryPath;
@property (nonatomic, strong) NSMutableArray* fileSystems;

@property BOOL userHasAllowed;

@end

#define kW3FileTemporary @"temporary"
#define kW3FilePersistent @"persistent"
