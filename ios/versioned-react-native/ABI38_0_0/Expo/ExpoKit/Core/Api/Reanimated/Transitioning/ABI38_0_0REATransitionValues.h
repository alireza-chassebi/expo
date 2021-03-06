#import <UIKit/UIKit.h>

@interface ABI38_0_0REATransitionValues : NSObject

@property (nonatomic) CGPoint center;
@property (nonatomic) CGRect bounds;
@property (nonatomic) CGPoint centerRelativeToRoot;
@property (nonatomic, retain) UIView *view;
@property (nonatomic, retain) UIView *parent;
@property (nonatomic, retain) UIView *ABI38_0_0ReactParent;
@property (nonatomic) CGPoint centerInABI38_0_0ReactParent;

- (instancetype)initWithView:(UIView *)view forRoot:(UIView *)root;

@end
