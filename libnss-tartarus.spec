Name: libnss-tartarus
Version: 0.0.1
Release: alt1

Summary: NSS library module for Tartarus

License: %gpl2plus
URL: http://tartarus.ru/
Group: System/Libraries
Packager: Evgeny Sinelnikov <sin@altlinux.ru>

Source: %name-%version.tar

Requires: libnss-role Tartarus-SysDB-slice

Requires(pre): chrooted >= 0.3.5-alt1 chrooted-resolv sed
Requires(postun): chrooted >= 0.3.5-alt1 sed

BuildRequires: gcc-c++ glibc-devel scons
#BuildRequires: boost-devel boost-iostreams-devel boost-program-options-devel
BuildRequires(pre): rpm-build-licenses

%description
NSS library module for Tartarus.

%package -n nss-tartarus-daemon
Summary: Authorization proxy and cache daemon for Tartarus
Group: System/Servers
Requires: %name = %version-%release

%description -n nss-tartarus-daemon
Authorization proxy and cache daemon for Tartarus

%prep
%setup -q

%build
scons

%install
scons install DESTDIR=%buildroot
mkdir -p %buildroot%_sysconfdir/Tartarus
touch %buildroot%_sysconfdir/role
cp config.service %buildroot%_sysconfdir/Tartarus/tnscd.conf

mkdir -p %buildroot%_initdir
cp tnscd.init.%_vendor %buildroot%_initdir/tnscd

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
%post_service %name

%preun -n nss-tartarus-daemon
%preun_service %name

%files
/%_lib/libnss_*.so.*

%files -n nss-tartarus-daemon
%_sbindir/*
%_initdir/*
%config(noreplace) %_sysconfdir/Tartarus/tnscd.conf

%changelog
* Fri Jul 11 2008 Evgeny Sinelnikov <sin@altlinux.ru> 0.0.1-alt1
- Initial rpm build for ALT Linux Sisyphus

