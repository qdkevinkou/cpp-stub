///////////////////////////////////////////////////////////////////////////////
// Include files 
//
#define __ADDR_ANY_DEBUG__
#include "addr_any.h"
#include "stub.h"


using namespace std;

static int foo()
{
    cout<<"I am foo"<<endl;
    return 0;
}

int foo_stub()
{   
    cout<<"I am foo_stub"<<endl;
    return 0;
}




///////////////////////////////////////////////////////////////////////////////
// main 
//

int _tmain( int argc, const TCHAR* argv[] ) 
{

	const TCHAR* pSymName = _T("foo"); 
	const TCHAR* pFilePdbName =  _T("test_addr_any_win.pdb"); 
	const TCHAR* pFileExeName =  _T("test_addr_any_win.exe"); 
	PVOID foo_address = get_func_addr(pFileExeName, pFilePdbName, pSymName);

	_tprintf( _T("Address: %x  "), foo); 

	_tprintf( _T("Address: %x  "), foo_address); 

    Stub stub;
    stub.set(foo_address, foo_stub);
    foo();

	PVOID mm_address = get_func_addr_by_remote(_T("ntdll.dll"), _T("ZwReadVirtualMemory"));
	_tprintf( _T("ZwReadVirtualMemory_address: %x  "), mm_address); 

	return 0; 
}

