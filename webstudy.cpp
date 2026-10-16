<!DOCTYPE html>
<html lang="vi">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
<title>ÔnThi+ | Ôn thi trực tuyến</title>
<script src="https://cdn.tailwindcss.com/3.4.17"></script>
<style>
:root{--bg:#f6f7fb;--card:#fff;--text:#14182b;--muted:#5d6480;--line:#e4e7f1;--brand:#4f46e5;--brand2:#7c3aed;--accent:#f59e0b;--hero1:#4338ca;--hero2:#7c3aed;color-scheme:light;box-sizing:border-box;padding-top:env(safe-area-inset-top,0px);padding-bottom:env(safe-area-inset-bottom,0px)}
@media (prefers-color-scheme:dark){:root:not([data-theme="light"]){--bg:#0e1020;--card:#171a31;--text:#eceefb;--muted:#9aa1c4;--line:#262a4a;--brand:#818cf8;--brand2:#a78bfa;--hero1:#312e81;--hero2:#5b21b6;color-scheme:dark}}
:root[data-theme="dark"]{--bg:#0e1020;--card:#171a31;--text:#eceefb;--muted:#9aa1c4;--line:#262a4a;--brand:#818cf8;--brand2:#a78bfa;--hero1:#312e81;--hero2:#5b21b6;color-scheme:dark}
html{scroll-padding-top:env(safe-area-inset-top,0px)}
body{background:var(--bg);color:var(--text);font-family:'Segoe UI',system-ui,-apple-system,Roboto,sans-serif}
.card{background:var(--card);border:1px solid var(--line);border-radius:1rem}
.muted{color:var(--muted)}
.hero{background:linear-gradient(135deg,var(--hero1),var(--hero2));color:#fff}
.tile{background:rgba(255,255,255,.14);backdrop-filter:blur(6px);border:1px solid rgba(255,255,255,.22);border-radius:1rem}
.btn{background:linear-gradient(135deg,var(--brand),var(--brand2));color:#fff;border-radius:.75rem;font-weight:600}
.inp{background:var(--bg);border:1px solid var(--line);color:var(--text);border-radius:.6rem;padding:.5rem .75rem}
.num{font-variant-numeric:tabular-nums}
.chip{border:1px solid var(--line);background:var(--card);border-radius:999px;padding:.3rem .8rem;font-size:.85rem;white-space:nowrap}
.chip.on{background:var(--brand);border-color:var(--brand);color:#fff}
.ib{border:1px solid var(--line);border-radius:.6rem;padding:.35rem .6rem;font-size:.85rem}
.ib:hover{border-color:var(--brand)}
.row{display:flex;gap:.5rem;overflow-x:auto;padding-bottom:.25rem}
</style>
</head>
<body>
<header class="sticky top-0 z-20 border-b" style="background:var(--card);border-color:var(--line);padding-top:env(safe-area-inset-top,0px)">
  <div class="max-w-6xl mx-auto px-4 h-14 flex items-center justify-between">
    <div class="font-extrabold text-lg flex items-center gap-2"><span>🎓</span><span>Ôn<span style="color:var(--brand)">Thi+</span></span></div>
    <nav class="hidden md:flex gap-6 text-sm muted font-medium">
      <a href="#" style="color:var(--brand)">Trang chủ</a><a href="#library">Thư viện</a><a href="#">Đề thi</a><a href="#">Lộ trình</a><a href="#">Bảng xếp hạng</a>
    </nav>
    <button id="themeBtn" class="inp text-sm" aria-label="Đổi giao diện">🌓</button>
  </div>
</header>
 
<main class="max-w-6xl mx-auto px-4 py-6 space-y-6">
  <!-- Banner đếm ngược -->
  <section class="hero rounded-3xl p-6 md:p-10 shadow-lg">
    <p class="text-sm opacity-80">Xin chào! Hãy cố gắng nhé 💪</p>
    <h1 class="text-2xl md:text-4xl font-extrabold mt-1">Còn bao lâu nữa đến <span id="examName">kỳ thi</span>?</h1>
    <p id="examDateText" class="opacity-80 mt-1 text-sm"></p>
 
    <div id="cd" class="grid grid-cols-4 gap-2 md:gap-4 mt-6 max-w-2xl">
      <div class="tile text-center py-3 md:py-5"><div id="d" class="num text-3xl md:text-5xl font-extrabold">00</div><div class="text-xs md:text-sm opacity-80">Ngày</div></div>
      <div class="tile text-center py-3 md:py-5"><div id="h" class="num text-3xl md:text-5xl font-extrabold">00</div><div class="text-xs md:text-sm opacity-80">Giờ</div></div>
      <div class="tile text-center py-3 md:py-5"><div id="m" class="num text-3xl md:text-5xl font-extrabold">00</div><div class="text-xs md:text-sm opacity-80">Phút</div></div>
      <div class="tile text-center py-3 md:py-5"><div id="s" class="num text-3xl md:text-5xl font-extrabold">00</div><div class="text-xs md:text-sm opacity-80">Giây</div></div>
    </div>
    <p id="done" class="hidden mt-6 text-xl font-bold">🎉 Đã đến ngày thi — chúc bạn thi tốt!</p>
 
    <div class="tile mt-6 p-4 grid md:grid-cols-[1fr_1fr_auto] gap-3 max-w-3xl">
      <label class="text-sm">Chọn kỳ thi
        <select id="preset" class="inp w-full mt-1"></select>
      </label>
      <div class="grid grid-cols-1 gap-3 md:contents" id="customBox">
        <label class="text-sm">Ngày thi (tự đặt)
          <input id="date" type="date" class="inp w-full mt-1">
        </label>
      </div>
      <button id="save" class="btn px-5 py-2 self-end">Lưu mục tiêu</button>
      <label id="nameWrap" class="text-sm md:col-span-3 hidden">Tên kỳ thi
        <input id="cname" type="text" maxlength="40" placeholder="VD: IELTS, Giữa kỳ Toán..." class="inp w-full mt-1">
      </label>
    </div>
  </section>
 
  <!-- Thống kê -->
  <section>
    <div class="flex items-center justify-between mb-3">
      <h2 class="text-lg font-bold">Tiến độ học tập của bạn</h2>
      <button id="demo" class="btn text-sm px-4 py-2">+ Làm đề nhanh (demo)</button>
    </div>
    <div class="grid grid-cols-1 sm:grid-cols-3 gap-4">
      <div class="card p-5"><div class="text-2xl">📝</div><div id="sDone" class="num text-3xl font-extrabold mt-2">0</div><div class="muted text-sm">Số đề đã làm</div></div>
      <div class="card p-5"><div class="text-2xl">🎯</div><div id="sAvg" class="num text-3xl font-extrabold mt-2">0</div><div class="muted text-sm">Điểm trung bình (thang 10)</div></div>
      <div class="card p-5"><div class="text-2xl">🔥</div><div id="sStreak" class="num text-3xl font-extrabold mt-2">0</div><div class="muted text-sm">Chuỗi ngày học liên tiếp</div></div>
    </div>
    <div class="card p-5 mt-4">
      <div class="flex justify-between text-sm mb-2"><span class="font-semibold">Mục tiêu: 50 đề</span><span id="goalTxt" class="muted"></span></div>
      <div class="h-3 rounded-full overflow-hidden" style="background:var(--line)"><div id="bar" class="h-full rounded-full" style="width:0;background:linear-gradient(90deg,var(--brand),var(--accent));transition:width .5s"></div></div>
    </div>
  </section>
<!-- Thư viện -->
  <section id="library" class="space-y-4">
    <div class="flex flex-wrap items-end justify-between gap-2">
      <div><h2 class="text-lg font-bold">📚 Thư viện & Tài liệu</h2><p class="muted text-sm">Tìm nhanh tài liệu theo môn, cấp độ và chuyên đề.</p></div>
      <span id="libCount" class="muted text-sm"></span>
    </div>
    <div class="card p-4 space-y-3">
      <input id="q" type="search" autocomplete="off" placeholder="Tìm kiếm thông minh: gõ 'tich phan', 'ielts', 'dien phan'... (không cần dấu)" class="inp w-full">
      <div class="row text-sm items-center"><span class="muted">Gợi ý:</span><span id="sugg" class="flex gap-2"></span></div>
      <div id="fSubj" class="row"></div>
      <div class="flex flex-wrap gap-3 items-center">
        <select id="fLvl" class="inp text-sm"></select>
        <select id="fTopic" class="inp text-sm"></select>
        <div id="fType" class="row"></div>
        <button id="fSaved" class="chip">⭐ Đã lưu (<span id="bmN">0</span>)</button>
        <button id="fReset" class="text-sm muted underline">Xóa bộ lọc</button>
      </div>
    </div>
    <div id="libGrid" class="grid sm:grid-cols-2 lg:grid-cols-3 gap-4"></div>
    <p id="libEmpty" class="hidden text-center muted py-10">Không tìm thấy tài liệu phù hợp. Thử bỏ bớt bộ lọc nhé.</p>
  </section>
</main>
<div id="modal" class="hidden fixed inset-0 z-30 flex items-center justify-center p-4" style="background:rgba(8,10,25,.65)">
  <div class="card w-full max-w-2xl max-h-full overflow-auto p-5">
    <div class="flex justify-between items-start gap-3"><div><h3 id="mTitle" class="font-bold text-lg"></h3><p id="mMeta" class="muted text-sm"></p></div><button id="mClose" class="ib" aria-label="Đóng">✕</button></div>
    <div id="mBody" class="mt-4"></div>
    <div class="flex gap-2 mt-4 justify-end"><button id="mBm" class="ib"></button><button id="mDl" class="btn px-4 py-2 text-sm">⬇ Tải xuống</button></div>
  </div>
</div>
<div id="toast" class="hidden fixed left-1/2 -translate-x-1/2 bottom-6 z-40 btn px-4 py-2 text-sm shadow-lg"></div>
<footer class="text-center text-sm muted py-6">© 2026 ÔnThi+ — Học đều mỗi ngày, thành công sẽ đến.</footer>
 
<script>
const $=id=>document.getElementById(id);
const PRESETS=[
  {k:'thpt',n:'Kỳ thi tốt nghiệp THPT 2027 (dự kiến)',d:'2027-06-26'},
  {k:'dgnl',n:'Đánh giá năng lực (dự kiến)',d:'2027-04-10'},
  {k:'custom',n:'Tự đặt ngày thi...',d:''}
];
const DEF={exam:{k:'thpt',n:PRESETS[0].n,d:PRESETS[0].d},stats:{done:12,sum:93.5,streak:5,last:''}};
let S;
function load(){try{S=JSON.parse(localStorage.getItem('onthi')||'null')}catch(e){S=null}
  if(!S)S=JSON.parse(JSON.stringify(DEF));}
function save(){try{localStorage.setItem('onthi',JSON.stringify(S))}catch(e){}}
const pad=n=>String(n).padStart(2,'0');
const today=()=>new Date().toISOString().slice(0,10);
 
function renderPreset(){
  $('preset').innerHTML=PRESETS.map(p=>`<option value="${p.k}">${p.n}</option>`).join('');
  $('preset').value=S.exam.k;
  $('date').value=S.exam.d;
  $('cname').value=S.exam.k==='custom'?S.exam.n:'';
  $('nameWrap').classList.toggle('hidden',S.exam.k!=='custom');
}
function tick(){
  const e=S.exam;
  $('examName').textContent=e.n||'kỳ thi';
  if(!e.d){$('examDateText').textContent='Hãy chọn ngày thi mục tiêu';return}
  const t=new Date(e.d+'T00:00:00');
  $('examDateText').textContent='Ngày thi: '+t.toLocaleDateString('vi-VN',{weekday:'long',day:'2-digit',month:'2-digit',year:'numeric'});
  let diff=Math.floor((t-new Date())/1000);
  const over=diff<=0; if(over)diff=0;
  $('cd').classList.toggle('hidden',over);$('done').classList.toggle('hidden',!over);
  $('d').textContent=pad(Math.floor(diff/86400));
  $('h').textContent=pad(Math.floor(diff%86400/3600));
  $('m').textContent=pad(Math.floor(diff%3600/60));
  $('s').textContent=pad(diff%60);
}
function renderStats(){
  const s=S.stats;
  $('sDone').textContent=s.done;
  $('sAvg').textContent=s.done?(s.sum/s.done).toFixed(1):'0.0';
  $('sStreak').textContent=s.streak+' ngày';
  const pct=Math.min(100,Math.round(s.done/50*100));
  $('bar').style.width=pct+'%';$('goalTxt').textContent=s.done+'/50 đề ('+pct+'%)';
}
$('preset').onchange=()=>{
  const p=PRESETS.find(x=>x.k===$('preset').value);
  $('nameWrap').classList.toggle('hidden',p.k!=='custom');
  if(p.d)$('date').value=p.d;
};
$('save').onclick=()=>{
  const k=$('preset').value,p=PRESETS.find(x=>x.k===k),d=$('date').value;
  if(!d){$('date').focus();return}
  const n=(k==='custom'?($('cname').value.trim()||'kỳ thi của bạn'):p.n);
  S.exam={k:(k!=='custom'&&d!==p.d)?'custom':k,n:(k!=='custom'&&d!==p.d)?p.n:n,d};
  save();renderPreset();tick();
};
$('demo').onclick=()=>{
  const sc=Math.round((5+Math.random()*5)*10)/10,td=today(),st=S.stats;
  st.done++;st.sum+=sc;
  if(st.last!==td){
    const y=new Date(Date.now()-864e5).toISOString().slice(0,10);
    st.streak=(st.last===y||!st.last)?st.streak+1:1;st.last=td;
  }
  save();renderStats();
};
$('themeBtn').onclick=()=>{
  const r=document.documentElement,dark=getComputedStyle(r).colorScheme==='dark';
  r.dataset.theme=dark?'light':'dark';
};
/* ===== Thư viện ===== */
const LIB=[
{id:1,s:'Toán',l:'Lớp 12',t:'Hàm số',k:'pdf',n:'50 bài toán khảo sát hàm số',m:'48 trang'},
{id:2,s:'Toán',l:'Lớp 12',t:'Tích phân',k:'video',n:'Bài giảng tích phân từ cơ bản đến nâng cao',m:'42 phút'},
{id:3,s:'Toán',l:'Lớp 12',t:'Tích phân',k:'mind',n:'Sơ đồ tư duy: công thức nguyên hàm – tích phân',m:'1 trang'},
{id:4,s:'Toán',l:'Lớp 11',t:'Hình học không gian',k:'pdf',n:'Chuyên đề quan hệ vuông góc trong không gian',m:'36 trang'},
{id:5,s:'Vật lý',l:'Lớp 12',t:'Dao động cơ',k:'video',n:'Con lắc lò xo & con lắc đơn – dạng bài hay gặp',m:'35 phút'},
{id:6,s:'Vật lý',l:'Lớp 12',t:'Điện xoay chiều',k:'pdf',n:'Tổng hợp công thức điện xoay chiều',m:'20 trang'},
{id:7,s:'Vật lý',l:'Lớp 12',t:'Dao động cơ',k:'mind',n:'Sơ đồ tư duy: dao động điều hòa',m:'1 trang'},
{id:8,s:'Hóa học',l:'Lớp 12',t:'Este – Lipit',k:'pdf',n:'Bài tập este – lipit có đáp án chi tiết',m:'28 trang'},
{id:9,s:'Hóa học',l:'Lớp 12',t:'Điện phân',k:'video',n:'Phương pháp giải nhanh bài toán điện phân',m:'30 phút'},
{id:10,s:'Hóa học',l:'Lớp 11',t:'Este – Lipit',k:'mind',n:'Sơ đồ tư duy: hợp chất hữu cơ chứa oxi',m:'1 trang'},
{id:11,s:'Tiếng Anh',l:'Ôn thi tốt nghiệp',t:'Ngữ pháp',k:'pdf',n:'Tổng ôn 12 thì & câu điều kiện',m:'32 trang'},
{id:12,s:'Tiếng Anh',l:'Ôn thi tốt nghiệp',t:'Từ vựng',k:'video',n:'1000 từ vựng thường gặp trong đề thi',m:'50 phút'},
{id:13,s:'Tiếng Anh',l:'Lớp 10',t:'Ngữ pháp',k:'mind',n:'Sơ đồ tư duy: các loại mệnh đề',m:'1 trang'},
{id:14,s:'Ngữ văn',l:'Ôn thi tốt nghiệp',t:'Nghị luận xã hội',k:'pdf',n:'Dàn ý & bài mẫu nghị luận xã hội 200 chữ',m:'24 trang'},
{id:15,s:'Ngữ văn',l:'Lớp 12',t:'Văn học 12',k:'video',n:'Phân tích Vợ chồng A Phủ',m:'38 phút'},
{id:16,s:'Ngữ văn',l:'Lớp 12',t:'Văn học 12',k:'mind',n:'Sơ đồ tư duy: tác phẩm văn học 12',m:'2 trang'}
];
const SUBJ=['Tất cả','Toán','Vật lý','Hóa học','Tiếng Anh','Ngữ văn'];
const TY={pdf:['📄','PDF'],video:['🎬','Video'],mind:['🧠','Sơ đồ tư duy']};
const SUG=['tích phân','dao động','điện phân','ngữ pháp','nghị luận'];
const LV=[...new Set(LIB.map(x=>x.l))];
let F={q:'',s:'Tất cả',l:'',t:'',k:'',saved:false};
let BM=new Set();try{BM=new Set(JSON.parse(localStorage.getItem('onthi_bm')||'[]'))}catch(e){}
const norm=s=>s.normalize('NFD').replace(/[\u0300-\u036f]/g,'').replace(/đ/g,'d').toLowerCase();
function toast(t){const e=$('toast');e.textContent=t;e.classList.remove('hidden');clearTimeout(toast.t);toast.t=setTimeout(()=>e.classList.add('hidden'),2200)}
function toggleBm(id){BM.has(id)?BM.delete(id):BM.add(id);try{localStorage.setItem('onthi_bm',JSON.stringify([...BM]))}catch(e){}renderLib()}
function renderLib(){
  $('fSubj').innerHTML=SUBJ.map(s=>`<button class="chip ${F.s===s?'on':''}" data-s="${s}">${s}</button>`).join('');
  $('fLvl').innerHTML='<option value="">Mọi cấp độ</option>'+LV.map(l=>`<option ${F.l===l?'selected':''}>${l}</option>`).join('');
  const tops=[...new Set(LIB.filter(x=>F.s==='Tất cả'||x.s===F.s).map(x=>x.t))];
  if(F.t&&!tops.includes(F.t))F.t='';
  $('fTopic').innerHTML='<option value="">Mọi chuyên đề</option>'+tops.map(t=>`<option ${F.t===t?'selected':''}>${t}</option>`).join('');
  $('fType').innerHTML=Object.entries(TY).map(([k,v])=>`<button class="chip ${F.k===k?'on':''}" data-k="${k}">${v[0]} ${v[1]}</button>`).join('');
  $('fSaved').classList.toggle('on',F.saved);$('bmN').textContent=BM.size;
  const toks=norm(F.q).split(/\s+/).filter(Boolean);
  const L=LIB.filter(x=>(F.s==='Tất cả'||x.s===F.s)&&(!F.l||x.l===F.l)&&(!F.t||x.t===F.t)&&(!F.k||x.k===F.k)&&(!F.saved||BM.has(x.id))
    &&toks.every(t=>norm([x.n,x.s,x.l,x.t,TY[x.k][1]].join(' ')).includes(t)));
  $('libCount').textContent=L.length+' tài liệu';
  $('libEmpty').classList.toggle('hidden',L.length>0);
  $('libGrid').innerHTML=L.map(x=>`<article class="card p-4 flex flex-col gap-2">
    <div class="flex justify-between text-xs"><span class="chip" style="padding:.1rem .6rem">${TY[x.k][0]} ${TY[x.k][1]}</span><span class="muted">${x.m}</span></div>
    <h3 class="font-semibold leading-snug">${x.n}</h3>
    <p class="muted text-xs">${x.s} · ${x.l} · ${x.t}</p>
    <div class="flex gap-2 mt-auto pt-2">
      <button class="ib flex-1" data-a="view" data-id="${x.id}">👁 Xem trước</button>
      <button class="ib" data-a="bm" data-id="${x.id}" aria-label="Đánh dấu">${BM.has(x.id)?'⭐':'☆'}</button>
      <button class="ib" data-a="dl" data-id="${x.id}" aria-label="Tải xuống">⬇</button>
    </div></article>`).join('');
}
let cur=null;
function preview(x){
  cur=x;$('mTitle').textContent=x.n;$('mMeta').textContent=`${TY[x.k][1]} · ${x.s} · ${x.l} · ${x.t} · ${x.m}`;
  const bar=w=>`<div style="height:8px;border-radius:4px;background:#d8dbe8;width:${w}%;margin:8px 0"></div>`;
  let h='';
  if(x.k==='pdf')h=`<div style="background:#fff;color:#222;border:1px solid var(--line);border-radius:.5rem;padding:24px;max-height:300px;overflow:auto"><div style="font-weight:700;margin-bottom:10px">${x.n}</div>${[95,88,92,70,96,85,60,94,90,75,92,80].map(bar).join('')}<p style="font-size:12px;color:#888;margin-top:12px">Xem trước trang 1/${parseInt(x.m)||1}</p></div>`;
  else if(x.k==='video')h=`<div style="aspect-ratio:16/9;background:#0b0d1a;border-radius:.6rem;display:flex;align-items:center;justify-content:center;color:#fff;font-size:56px">▶<span style="font-size:14px;margin-left:12px;opacity:.7">${x.m}</span></div>`;
  else h=`<svg viewBox="0 0 480 260" width="100%" style="background:var(--bg);border-radius:.6rem"><g stroke="var(--brand)" stroke-width="2" fill="none"><path d="M240 130 L90 50"/><path d="M240 130 L390 50"/><path d="M240 130 L90 210"/><path d="M240 130 L390 210"/></g><g font-size="13" text-anchor="middle" fill="#fff"><rect x="170" y="110" width="140" height="40" rx="20" fill="var(--brand)"/><text x="240" y="135">${x.t}</text><g fill="var(--brand2)"><rect x="30" y="30" width="120" height="36" rx="10"/><rect x="330" y="30" width="120" height="36" rx="10"/><rect x="30" y="192" width="120" height="36" rx="10"/><rect x="330" y="192" width="120" height="36" rx="10"/></g><text x="90" y="53">Khái niệm</text><text x="390" y="53">Công thức</text><text x="90" y="215">Dạng bài</text><text x="390" y="215">Lưu ý</text></g></svg>`;
  $('mBody').innerHTML=h;$('mBm').textContent=BM.has(x.id)?'⭐ Đã lưu':'☆ Lưu';$('modal').classList.remove('hidden');
}
const close=()=>$('modal').classList.add('hidden');
$('q').oninput=e=>{F.q=e.target.value;renderLib()};
$('sugg').innerHTML=SUG.map(s=>`<button class="chip" data-q="${s}">${s}</button>`).join('');
$('sugg').onclick=e=>{const q=e.target.dataset.q;if(q){F.q=q;$('q').value=q;renderLib()}};
$('fSubj').onclick=e=>{if(e.target.dataset.s){F.s=e.target.dataset.s;renderLib()}};
$('fType').onclick=e=>{const k=e.target.dataset.k;if(k){F.k=F.k===k?'':k;renderLib()}};
$('fLvl').onchange=e=>{F.l=e.target.value;renderLib()};
$('fTopic').onchange=e=>{F.t=e.target.value;renderLib()};
$('fSaved').onclick=()=>{F.saved=!F.saved;renderLib()};
$('fReset').onclick=()=>{F={q:'',s:'Tất cả',l:'',t:'',k:'',saved:false};$('q').value='';renderLib()};
$('libGrid').onclick=e=>{const b=e.target.closest('[data-a]');if(!b)return;const x=LIB.find(i=>i.id==b.dataset.id);
  if(b.dataset.a==='view')preview(x);else if(b.dataset.a==='bm')toggleBm(x.id);else toast('Đã thêm "'+x.n+'" vào hàng đợi tải xuống (demo)')};
$('mBm').onclick=()=>{toggleBm(cur.id);$('mBm').textContent=BM.has(cur.id)?'⭐ Đã lưu':'☆ Lưu'};
$('mDl').onclick=()=>toast('Đã thêm vào hàng đợi tải xuống (demo)');
$('mClose').onclick=close;$('modal').onclick=e=>{if(e.target.id==='modal')close()};
document.addEventListener('keydown',e=>{if(e.key==='Escape')close()});
renderLib();
load();renderPreset();renderStats();tick();setInterval(tick,1000);
</script>
</body>
</html>