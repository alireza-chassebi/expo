// Copyright 2016-present 650 Industries. All rights reserved.

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <ABI39_0_0UMBarCodeScannerInterface/ABI39_0_0UMBarCodeScannerInterface.h>

@interface ABI39_0_0EXBarCodeScanner : NSObject <ABI39_0_0UMBarCodeScannerInterface>

- (void)setSession:(AVCaptureSession *)session;
- (void)setSessionQueue:(dispatch_queue_t)sessionQueue;
- (void)setOnBarCodeScanned:(void (^)(NSDictionary *))onBarCodeScanned;

- (void)setIsEnabled:(BOOL)enabled;
- (void)setSettings:(NSDictionary<NSString *, id> *)settings;

- (void)setPreviewLayer:(AVCaptureVideoPreviewLayer *)previewLayer;

- (void)maybeStartBarCodeScanning;
- (void)stopBarCodeScanning;

@end
