//
//  ZAReallocOperation.h
//  AsyncDisplayKit
//
//  Created by Long Kim on 6/15/20.
//  Copyright © 2020 Pinterest. All rights reserved.
//

#ifndef ZAReallocOperation_h
#define ZAReallocOperation_h

#import <AsyncDisplayKit/ASBaseDefines.h>
#import <AsyncDisplayKit/ASCollectionElement.h>

NS_ASSUME_NONNULL_BEGIN

/// A subclass of @c NSBlockOperation, which manages @c ASCollectionElement node reallocation.
/// @discussion
/// Used to batch several reallocations together and executed on an arbitary @c NSOperationQueue.
@interface ZAReallocOperation : NSBlockOperation

@property (nonatomic, readonly) NSHashTable<ASCollectionElement *> *elements;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithElements:(NSSet<ASCollectionElement *> *)elements;

@end

NS_ASSUME_NONNULL_END

#endif /* ZAReallocOperation_h */
