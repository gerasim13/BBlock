//
//  BBlock.h
//  BBlock
//
//  Created by David Keegan on 4/10/12.
//  Copyright (c) 2012 David Keegan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// For when you need a weak reference of an object, example: `BBlockWeakObject(obj) wobj = obj;`
#define BBlockWeakObject(o) __typeof__(o) __weak

/// For when you need a weak reference to self, example: `BBlockWeakSelf wself = self;`
#define BBlockWeakSelf BBlockWeakObject(self)

@interface BBlock : NSObject

/// Execute the block on the main thread
+ (void)dispatchOnMainThread:(void (^)())block;

/// Execute the block on the main thread after a specified number of seconds
+ (void)dispatchAfter:(NSTimeInterval)delay onMainThread:(void (^)())block;

/// Exectute the block on a background thread but in a synchronous queue
+ (void)dispatchOnSynchronousQueue:(void (^)())block;

/// Exectute the block on a background thread but in a synchronous queue,
/// This queue should only be used for writing files to disk.
+ (void)dispatchOnSynchronousFileQueue:(void (^)())block;

+ (void)dispatchOnDefaultPriorityConcurrentQueue:(void (^)())block;
+ (void)dispatchOnLowPriorityConcurrentQueue:(void (^)())block;
+ (void)dispatchOnHighPriorityConcurrentQueue:(void (^)())block;

/// UIImage Helper Methods
+ (UIImage *)imageForSize:(CGSize)size withDrawingBlock:(void(^)())drawingBlock;
+ (UIImage *)imageForSize:(CGSize)size opaque:(BOOL)opaque withDrawingBlock:(void(^)())drawingBlock;
+ (UIImage *)imageWithIdentifier:(NSString *)identifier forSize:(CGSize)size andDrawingBlock:(void(^)())drawingBlock;
+ (UIImage *)imageWithIdentifier:(NSString *)identifier opaque:(BOOL)opaque forSize:(CGSize)size andDrawingBlock:(void(^)())drawingBlock;
+ (UIImage *)imageWithIdentifier:(NSString *)identifier;
+ (void)removeImageWithIdentifier:(NSString *)identifier;
+ (void)removeAllImages;

@end
