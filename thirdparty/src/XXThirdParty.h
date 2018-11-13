//
//  XXThirdParty.h
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/13.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#ifndef XXThirdParty_h
#define XXThirdParty_h

#ifdef SP
#undef SP
#endif
#define SP std::shared_ptr

#ifdef WP
#undef WP
#endif
#define WP std::weak_ptr

#endif /* XXThirdParty_h */
