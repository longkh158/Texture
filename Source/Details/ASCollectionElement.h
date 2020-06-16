//
//  ASCollectionElement.h
//  Texture
//
//  Copyright (c) Facebook, Inc. and its affiliates.  All rights reserved.
//  Changes after 4/13/2017 are: Copyright (c) Pinterest, Inc.  All rights reserved.
//  Licensed under Apache 2.0: http://www.apache.org/licenses/LICENSE-2.0
//

#import <AsyncDisplayKit/ASDataController.h>
#import <AsyncDisplayKit/ASTraitCollection.h>

@class ASDisplayNode;
@protocol ASRangeManagingNode;

NS_ASSUME_NONNULL_BEGIN

AS_SUBCLASSING_RESTRICTED
@interface ASCollectionElement : NSObject

@property (nullable, nonatomic, copy, readonly) NSString *supplementaryElementKind;
@property (nonatomic) ASSizeRange constrainedSize;
@property (nonatomic, weak, readonly) id<ASRangeManagingNode> owningNode;
@property (nonatomic) ASPrimitiveTraitCollection traitCollection;
@property (nullable, nonatomic, readonly) id nodeModel;

- (instancetype)initWithNodeModel:(nullable id)nodeModel
                        nodeBlock:(ASCellNodeBlock)nodeBlock
         supplementaryElementKind:(nullable NSString *)supplementaryElementKind
                  constrainedSize:(ASSizeRange)constrainedSize
                       owningNode:(id<ASRangeManagingNode>)owningNode
                  traitCollection:(ASPrimitiveTraitCollection)traitCollection;

#if ZA_ENABLE_MAINTAIN_RANGE
/// Deallocates a node if it falls out of maintain range.
- (void)deallocateNode;

/// Reacquires a node block, used in case when a node is about to be reallocated.
/// This will ask the data source to prepare a node block, if and only if one isn't
/// there yet.
/// @param nodeBlock A node block for a collection cell. Cannot be nil.
- (void)reacquireNodeBlockIfNeeded:(ASCellNodeBlock)nodeBlock;

/// Checks if an element's node has been deallocted (for example, when it fell out of maintain range).
@property (atomic, readonly, getter=isNodeDeallocated) BOOL nodeDeallocated;

#endif

/**
 * @return The node, running the node block if necessary. The node block will be discarded
 * after the first time it is run.
 */
@property (readonly) ASCellNode *node;

/**
 * @return The node, if the node block has been run already.
 */
@property (nullable, readonly) ASCellNode *nodeIfAllocated;

@end

NS_ASSUME_NONNULL_END
