//
//  ZARallocOperation.m
//  AsyncDisplayKit
//
//  Created by Long Kim on 6/15/20.
//  Copyright © 2020 Pinterest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZAReallocOperation.h"

#if ZA_ENABLE_MAINTAIN_RANGE
@implementation ZAReallocOperation

- (instancetype)initWithElements:(NSSet *)elements {
  if (self = [super init]) {
    NSHashTable *h = [[NSHashTable alloc] initWithOptions:NSHashTableObjectPointerPersonality capacity:elements.count];
    for (id e in elements) { [h addObject:e]; }
    _elements = h;
  }
  return self;
}

@end
#endif
