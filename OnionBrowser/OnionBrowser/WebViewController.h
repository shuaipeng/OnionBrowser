// This file is part of Onion Browser 1.7 - https://mike.tig.as/onionbrowser/
// Copyright © 2012-2016 Mike Tigas
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#import <UIKit/UIKit.h>
#import "NJKWebViewProgress.h"

#define TLSSTATUS_NO 0
#define TLSSTATUS_YES 1
#define TLSSTATUS_INSECURE 2
#define TLSSTATUS_PREVIOUS 255

extern const char AlertViewExternProtoUrl;
extern const char AlertViewIncomingUrl;

@interface WebViewController : UIViewController <UIWebViewDelegate, UITextFieldDelegate, UIAlertViewDelegate, NJKWebViewProgressDelegate> {
}

@property (strong, nonatomic) UIWebView *myWebView;
@property (nonatomic) UIToolbar* toolbar;
@property (nonatomic) UIBarButtonItem* backButton;
@property (nonatomic) UIBarButtonItem* forwardButton;
@property (nonatomic) UIBarButtonItem* toolButton;
@property (nonatomic) UIAlertController* optionsMenu;
@property (nonatomic) UIBarButtonItem* bookmarkButton;
@property (nonatomic) UIBarButtonItem* stopRefreshButton;
@property (nonatomic) UILabel* pageTitleLabel;
@property (nonatomic) UITextField* addressField;
@property (nonatomic) NSString *currentURL;

@property (nonatomic, retain) UINavigationController *bookmarkNavController;

@property (nonatomic) NSString *torStatus;

@property (nonatomic) Byte tlsStatus;


- (void)loadURL: (NSURL *)navigationURL;
- (void)askToLoadURL: (NSURL *)navigationURL;
- (void)addressBarCancel;
- (void)renderTorStatus: (NSString *)statusLine;

- (void)openOptionsMenu;
- (void)openSettingsView;
- (void)goForward;
- (void)goBack;
- (void)reload;
- (void)stopLoading;

- (void)prePopulateBookmarks;
- (void)showBookmarks;
- (void)addCurrentAsBookmark;
- (void)updateButtons;
- (void)updateTitle:(UIWebView*)aWebView;
- (void)updateAddress:(NSURLRequest*)request;
- (void)loadAddress:(id)sender event:(UIEvent*)event;
- (void)informError:(NSError*)error;

- (void)updateTLSStatus:(Byte)newStatus;
- (void)hideTLSStatus;

- (UIImage *)makeForwardBackButtonImage:(Boolean)whichButton;
@end
