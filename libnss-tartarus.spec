%define nsswitch %_sysconfdir/nsswitch.conf

Name: libnss-tartarus
Version: 0.0.4
Release: alt1

Summary: NSS library module for Tartarus

License: %gpl2plus
URL: http://tartarus.ru/
Group: System/Libraries
Packager: Evgeny Sinelnikov <sin@altlinux.ru>

Source: %name-%version.tar
Source1: tnscd.init.%_vendor

Requires: libnss-role
Requires: nss-tartarus-daemon = %version-%release
Requires: libice-ssl-krb

Requires(pre): chrooted >= 0.3.5-alt1 chrooted-resolv sed
Requires(postun): chrooted >= 0.3.5-alt1 sed

BuildRequires: boost-asio-devel boost-filesystem-devel
BuildRequires: libcom_err-devel libice-devel libjson_spirit-devel libkrb5user-devel
BuildRequires: gcc-c++ scons

BuildRequires(pre): rpm-build-licenses

BuildRequires: Tartarus-SysDB-slice
BuildRequires: libice-ssl-krb-devel
BuildRequires: libkrb5user-devel >= 0.1.0

%description
NSS library module for Tartarus.

%package -n nss-tartarus-daemon
Summary: Authorization proxy and cache daemon for Tartarus
Group: System/Servers

%description -n nss-tartarus-daemon
Authorization proxy and cache daemon for Tartarus

%prep
%setup -q

%build
scons

%install
scons install \
    --install-sandbox=%buildroot \
    --libdir=%_libdir \
    --libsysdir=/%_lib \
    --localstatedir=%_localstatedir
mkdir -p %buildroot%_sysconfdir/Tartarus/clients
cp tnscd.config %buildroot%_sysconfdir/Tartarus/clients/

mkdir -p %buildroot%_initdir
cp %SOURCE1 %buildroot%_initdir/tnscd

%post
%post_ldconfig
if [ "$1" = "1" ]; then
    cp %nsswitch %nsswitch.rpmorig
    grep -q '^passwd:[[:blank:]].\+tartarus' %nsswitch || \
    sed -i 's/^\(passwd:[[:blank:]].\+\)$/\1 tartarus/' %nsswitch
    if grep -q '^group:[[:blank:]].\+role' %nsswitch; then
        grep -q '^group:[[:blank:]].\+tartarus' %nsswitch || \
        sed -i 's/^\(group:[[:blank:]].\+\)\(role\)$/\1tartarus \2/' %nsswitch
    else
        grep -q '^group:[[:blank:]].\+tartarus' %nsswitch || \
        sed -i 's/^\(group:[[:blank:]].\+\)$/\1 tartarus role/' %nsswitch
    fi
fi
update_chrooted all

%postun
%postun_ldconfig
if [ "$1" = "0" ]; then
    sed -i -e 's/ tartarus//g' %nsswitch
fi
update_chrooted all

%post -n nss-tartarus-daemon
%post_service tnscd

%preun -n nss-tartarus-daemon
%preun_service tnscd

%files
/%_lib/libnss_*.so.*

%files -n nss-tartarus-daemon
%_sbindir/*
%_initdir/*
%config(noreplace) %_sysconfdir/Tartarus/clients/*
%dir %_localstatedir/tnscd

%changelog
* Fri Nov 21 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.4-alt1
- Add localstate directory checking and instalation
- Add signals handlers for daemon
- Add global config for unix socket

* Wed Nov 19 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.3-alt2
- Fix build at x86_64

* Wed Nov 19 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.3-alt1
- Build tnscd with alpha interface

* Wed Oct 22 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.2-alt2
- Fixed for using krb5user_set_ccname()

* Sun Sep 28 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.2-alt1
- Start to build with libkrb5user
- Fixed nsswitch.conf post/postun scripts

* Thu Sep 11 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.1-alt4
- Fixed buildrequires for new boost build
- Added genererated ice files depends
- Fixed Sconstruct

* Sat Jul 19 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.1-alt3
- Prerelease done

* Mon Jul 14 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.1-alt2
- Fix requires for nss module and daemon

* Fri Jul 11 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.1-alt1
- Initial rpm build for ALT Linux Sisyphus

