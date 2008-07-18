Name: libnss-tartarus
Version: 0.0.1
Release: alt3

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

# Automatically added by buildreq on Fri Jul 18 2008
BuildRequires: boost-datetime-devel boost-regex-devel boost-system-devel gcc-c++ libcom_err-devel libice-devel libjson_spirit-devel libkrb5-devel scons

BuildRequires(pre): rpm-build-licenses

BuildRequires: Tartarus-SysDB-slice
BuildRequires: libice-devel ice libice
BuildRequires: libice-ssl-krb-devel

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
scons install DESTDIR=%buildroot
mkdir -p %buildroot%_sysconfdir/Tartarus/clients
cp tnscd.config %buildroot%_sysconfdir/Tartarus/clients/

mkdir -p %buildroot%_initdir
cp %SOURCE1 %buildroot%_initdir/tnscd

%post
%post_ldconfig
grep -q '^group:[[:blank:]].\+tartarus' /etc/nsswitch.conf || \
sed -i.rpmorig 's/^\(group:[[:blank:]].\+\)\(role\)$/\1 tartarus \2/' /etc/nsswitch.conf
update_chrooted all

%postun
%postun_ldconfig
sed -i -e 's/ tartarus//' /etc/nsswitch.conf
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

%changelog
* Mon Jul 14 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.1-alt2
- Fix requires for nss module and daemon

* Fri Jul 11 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.1-alt1
- Initial rpm build for ALT Linux Sisyphus

