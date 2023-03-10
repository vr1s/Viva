#include "HomePlusEditor/Debug/KDBManager.h"
#include "HomePlusEditor/Debug/KDBOverlayView.h"

#define NSLog(...) [KDBManager.sharedInstance logString:[NSString stringWithFormat:__VA_ARGS__] file:__FILE__ line:__LINE__]

#define kViewframeWidth UIScreen.mainScreen.bounds.size.width/2
#define kViewframeHeight UIScreen.mainScreen.bounds.size.height/3


@implementation KDBManager {
@private
    UIView *_overlayView;
}

@synthesize overlayView = _overlayView;
@synthesize textView = _textView;
@synthesize textQueue = _textQueue;
@synthesize open = _open;

- (instancetype)init
{
    self = [super init];

    if (self)
    {
        _textQueue = @"";
    }

    return self;
}

+ (instancetype)sharedInstance
{
    static id _sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
    {
        _sharedInstance = [[self alloc] init];
    });

    return _sharedInstance;
}

- (UIView *)overlayView 
{
    if (!_overlayView) {
        _overlayView = [[KDBOverlayView alloc] initWithFrame:CGRectMake(0,0,600,400)];
        [_overlayView addSubview:[self textView]];
        _overlayView.backgroundColor = [UIColor colorWithWhite:0.0 alpha:0.6];
        _overlayView.layer.cornerRadius = 10;

    }
    return _overlayView;
}

- (void)setupOverlayView 
{
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenWidth = screenRect.size.width;
    CGFloat screenHeight = screenRect.size.height;
    self.overlayView.frame = CGRectMake(screenWidth - 20, 80, kViewframeWidth, kViewframeHeight);
    UITapGestureRecognizer *singleFingerTap = [[UITapGestureRecognizer alloc] initWithTarget:self 
                                          action:@selector(handleTap:)];
    [_overlayView addGestureRecognizer:singleFingerTap];
    [self handleTap:nil];
}

- (void)handleTap:(UITapGestureRecognizer *)recognizer
{
    if (_open)
    {
        _open = NO;
        [UIView animateWithDuration:0.2 animations:^{
            _overlayView.transform = CGAffineTransformTranslate(_overlayView.transform, kViewframeWidth, 0);
        }];
    }
    else 
    {
        _open = YES;
        [UIView animateWithDuration:0.2 animations:^{
            _overlayView.transform = CGAffineTransformTranslate(_overlayView.transform, -kViewframeWidth, 0);
        }];
    }
}

- (UITextView *)textView
{
    if (!_textView) {
        _textView = [[UITextView alloc] initWithFrame:CGRectMake(20,20,kViewframeWidth-40,kViewframeHeight-40)];
        _textView.text = _textQueue;
        _textView.backgroundColor = [UIColor colorWithWhite:0.0 alpha:0];
        _textView.editable = NO;
    }
    return _textView;
}

-(void)logString:(NSString *)string file:(char *)file line:(int)line
{
    NSString *displayString = [NSString stringWithFormat:@"%s:%d - %@", file, line, string];
    if (_textView) {
        _textView.text = [NSString stringWithFormat:@"%@%@\n", _textView.text, displayString];
    }
    else 
    {
        _textQueue = [NSString stringWithFormat:@"%@%@\n", _textQueue, displayString];
    }
}

@end