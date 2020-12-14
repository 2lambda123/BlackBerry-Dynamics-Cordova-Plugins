/*
 Copyright (c) 2020 BlackBerry Limited. All Rights Reserved.
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

#import "CDVFileBD.h"

@interface CDVLocalFilesystemBD : NSObject<CDVFileSystemBD> {
    NSString *_name;
    NSString *_fsRoot;
}

- (id) initWithName:(NSString *)name root:(NSString *)fsRoot;
+ (NSString*)getMimeTypeFromPath:(NSString*)fullPath;

@property (nonatomic,strong) NSString *fsRoot;

@end
