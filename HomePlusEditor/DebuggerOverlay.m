#ifndef NDEBUG


@implementation KDBOverlayView
@end

@implementation KDBManager {
@private
    UIView *_overlayView;
}

@synthesize overlayView = _overlayView;
@synthesize textView = _textView;
@synthesize textQueue = _textQueue;
@synthesize open = _open;
@synthesize started = _started;

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
    static KDBManager* _sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
    {
        _sharedInstance = [[self alloc] init];
    });
    if (!_sharedInstance.started)
        [_sharedInstance setupOverlayView];

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
    if (![HPGestureManager sharedInstance].systemGestureView)
        return;
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenWidth = screenRect.size.width;
    CGFloat screenHeight = screenRect.size.height;
    self.overlayView.frame = CGRectMake(screenWidth - 20, 80, kViewframeWidth, kViewframeHeight);
    UITapGestureRecognizer *singleFingerTap = [[UITapGestureRecognizer alloc] initWithTarget:self 
                                          action:@selector(handleTap:)];
    [_overlayView addGestureRecognizer:singleFingerTap];
    // uncom to start opened 
    // [self handleTap:nil];
    [[HPGestureManager sharedInstance].systemGestureView.superview addSubview:_overlayView];
    _started = YES;
    NSLog(@"Log Overlay Initialized");
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

#endif
