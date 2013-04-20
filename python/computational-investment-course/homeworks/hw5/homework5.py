#!/hfe/ova/rai clguba

vzcbeg cnaqnf nf cq
vzcbeg ahzcl nf ac
vzcbeg qngrgvzr nf qg
vzcbeg zngcybgyvo.clcybg nf cyg

# DFGX
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn


qrs ernq_lnubb_qngn(fgneg_qngr, raq_qngr, yf_flzobyf, yf_xrlf=['pybfr']):
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(fgneg_qngr, raq_qngr, qg.gvzrqrygn(ubhef=16))
    qngnbow = qn.QngnNpprff('Lnubb')
    erghea qngnbow.trg_qngn(yqg_gvzrfgnzcf, yf_flzobyf, yf_xrlf)[0].fbeg(nkvf=1)


qrs fzn_puneg(gvzrfgnzcf, qngn, ybbxonpx=20):
    fzn = cq.ebyyvat_zrna(qngn, ybbxonpx)
    cyg.cybg(gvzrfgnzcf, qngn, ynory=yf_flzobyf[0])
    cyg.cybg(gvzrfgnzcf, fzn, ynory="Zbivat NIT")
    cyg.yrtraq()
    cyg.lynory('Ergheaf')
    cyg.kynory('Qngr')

    cyg.fnirsvt('ubzrjbex5_fzn.cqs', sbezng='cqs')


qrs obyyvatre_puneg(gvzrfgnzcf, qngn, ybbxonpx=20):
    fzn = cq.ebyyvat_zrna(qngn, ybbxonpx)
    hccre = fzn + cq.ebyyvat_fgq(qngn, ybbxonpx)
    ybjre = fzn - cq.ebyyvat_fgq(qngn, ybbxonpx)

    cyg.cybg(yqg_gvzrfgnzcf, qngn, ynory=yf_flzobyf[0])
    cyg.cybg(yqg_gvzrfgnzcf, fzn, ynory="Zbivat NIT")
    cyg.cybg(yqg_gvzrfgnzcf, hccre, ynory="hccre onaq")
    cyg.cybg(yqg_gvzrfgnzcf, ybjre, ynory="ybjre onaq")
    cyg.yrtraq(ybp=3)
    cyg.lynory('Ergheaf')
    cyg.kynory('Qngr')

    cyg.fnirsvt('ubzrjbex5_obyyvatre.cqs', sbezng='cqs')


vs __anzr__ == '__znva__':
    ybbxonpx = 20

    fgneg_qngr = qg.qngrgvzr(2010, 1, 1)
    raq_qngr = qg.qngrgvzr(2010, 12, 31)
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(fgneg_qngr, raq_qngr, qg.gvzrqrygn(ubhef=16))
    yf_flzobyf = ["TBBT", "NNCY", "VOZ", "ZFSG"]

    fgbpx_qngn = ernq_lnubb_qngn(fgneg_qngr, raq_qngr, yf_flzobyf)

    fzn_puneg(yqg_gvzrfgnzcf, fgbpx_qngn, ybbxonpx)
    cyg.pys()
    obyyvatre_puneg(yqg_gvzrfgnzcf, fgbpx_qngn, ybbxonpx)

    fzn = cq.ebyyvat_zrna(fgbpx_qngn, ybbxonpx)
    fgq = cq.ebyyvat_fgq(fgbpx_qngn, ybbxonpx)

    oby = (fgbpx_qngn - fzn) / fgq
    cevag oby.gnvy(5)
