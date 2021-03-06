//
//  EGORefreshTableHeaderView.h
//  Demo
//
//  Created by Devin Doty on 10/14/09
//  Copyright 2009 enormego. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>


typedef enum {
    EGOOPullRefreshPulling,
    EGOOPullRefreshNormal,
    EGOOPullRefreshLoading,
} EGOPullRefreshState;


typedef enum {
    EGOStyleBlue,
    EGOStyleBlack,
    EGOStyleWhite,
    EGOStyleGrey,
} EGOStyle;


@protocol EGORefreshTableHeaderDelegate;

@interface EGORefreshTableHeaderView : UIView
{
    id _delegate;
    
    EGOPullRefreshState _state;
    
    CALayer *_arrowImage;
    
    UILabel *_lastUpdatedLabel;
    UILabel *_statusLabel;
    
    UIActivityIndicatorView *_activityView;
    
    NSString *_objectKey;
    
    EGOStyle _style;
    
    UIEdgeInsets _defaultInsets;
}

@property (nonatomic, assign) id <EGORefreshTableHeaderDelegate> delegate;

@property (nonatomic, retain) UIActivityIndicatorView *activityView;
@property (nonatomic, retain) CALayer *arrowImage;
@property (nonatomic, retain) UILabel *lastUpdatedLabel;
@property (nonatomic, retain) UILabel *statusLabel;

@property (nonatomic, copy) NSString *objectKey;

@property (assign) EGOStyle style;

@property (assign) UIEdgeInsets defaultInsets;

- (id)initWithFrame:(CGRect)frame style:(EGOStyle)style;
- (id)initWithView:(UIView *)view tableView:(UITableView *)tableView;
- (id)initWithView:(UIView *)view tableView:(UITableView *)tableView style:(EGOStyle)style;

- (id)initWithFrame:(CGRect)frame 
     arrowImageName:(NSString *)arrow 
          textColor:(UIColor *)textColor 
    backgroundColor:(UIColor *)backgroundColor
      activityStyle:(UIActivityIndicatorViewStyle)activityStyle;

- (void)egoRefreshScrollViewDataSourceDidFinishedLoading:(UIScrollView *)scrollView;
- (void)egoRefreshScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)egoRefreshScrollViewDidEndDragging:(UIScrollView *)scrollView;

- (void)refreshLastUpdatedDate;

@end


@protocol EGORefreshTableHeaderDelegate

- (void)egoRefreshTableHeaderDidTriggerRefresh:(EGORefreshTableHeaderView*)view;
- (BOOL)egoRefreshTableHeaderDataSourceIsLoading:(EGORefreshTableHeaderView*)view;

@optional

- (NSDate*)egoRefreshTableHeaderDataSourceLastUpdated:(EGORefreshTableHeaderView*)view;

@end
