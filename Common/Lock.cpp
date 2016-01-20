///////////////////////////////////////////////////////////////////////////////
//
// 版权所有(C), 2007, 商讯网信息有限公司
//
// 版本：1.0
// 文件说明：临界区操作类实现
// 生成日期：2007-4-10
// 作者：刘兆兵
//
// 修改历史：
// 1. 日期：
//   作者：
//   修改内容：
// 2. 
//
///////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "Lock.h"

///////////////////////////////////////////////////////////////////////////////
//
// 函数功能描述：构造函数，初始化临界区
// 输入：
// 输出：
// 返回值：
// 其它说明：
//
///////////////////////////////////////////////////////////////////////////////
CLock::CLock()
{
    InitializeCriticalSection(&m_crit);
}

///////////////////////////////////////////////////////////////////////////////
//
// 函数功能描述：析构函数，删除临界区
// 输入：
// 输出：
// 返回值：
// 其它说明：
//
///////////////////////////////////////////////////////////////////////////////
CLock::~CLock()
{
    DeleteCriticalSection(&m_crit);
}

///////////////////////////////////////////////////////////////////////////////
//
// 函数功能描述：加锁
// 输入：
// 输出：
// 返回值：
// 其它说明：
//
///////////////////////////////////////////////////////////////////////////////
void CLock::Lock()
{
    EnterCriticalSection(&m_crit);
}

///////////////////////////////////////////////////////////////////////////////
//
// 函数功能描述：解锁
// 输入：
// 输出：
// 返回值：
// 其它说明：
//
///////////////////////////////////////////////////////////////////////////////
void CLock::Unlock()
{
    LeaveCriticalSection(&m_crit);
}

///////////////////////////////////////////////////////////////////////////////
//
// 函数功能描述：构造函数，加锁
// 输入：
// 输出：
// 返回值：
// 其它说明：
//
///////////////////////////////////////////////////////////////////////////////
CLocalLock::CLocalLock(CLock * pLock)
{
    if (!pLock)
    {
        m_pLock = NULL;
        return;
    }

    m_pLock = pLock;
    m_pLock->Lock();
}

///////////////////////////////////////////////////////////////////////////////
//
// 函数功能描述：析构函数，解锁
// 输入：
// 输出：
// 返回值：
// 其它说明：
//
///////////////////////////////////////////////////////////////////////////////
CLocalLock::~CLocalLock()
{
    if (m_pLock)
    {
        m_pLock->Unlock();
    }
}