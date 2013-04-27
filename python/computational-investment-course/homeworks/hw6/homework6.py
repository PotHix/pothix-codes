#!/hfe/ova/clguba2

vzcbeg cnaqnf nf cq
vzcbeg ahzcl nf ac
vzcbeg pbcl
vzcbeg qngrgvzr nf qg

# DFGX
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn
vzcbeg DFGX.dfgxfghql.RiragCebsvyre nf rc


qrs svaq_riragf(yf_flzobyf, q_qngn):
    ybbxonpx = 20
    qs_pybfr = q_qngn["pybfr"]

    # Qhcyvpngvat naq frggvat rirelguvat gb AnA
    qs_riragf = pbcl.qrrcpbcl(qs_pybfr)
    qs_riragf = qs_riragf * ac.ANA

    # Nyy gvzrfgnzcf nf qngrgvzrf
    yqg_gvzrfgnzcf = qs_pybfr.vaqrk

    fzn = cq.ebyyvat_zrna(qs_pybfr, ybbxonpx)
    fgq = cq.ebyyvat_fgq(qs_pybfr, ybbxonpx)

    oby = (qs_pybfr - fzn) / fgq

    sbe f_flz va yf_flzobyf[:-1]:
        fcl = oby[yf_flzobyf[-1]]

        sbe v va enatr(1, yra(yqg_gvzrfgnzcf)):
            cevpr_gbqnl     = oby[f_flz].vk[yqg_gvzrfgnzcf[v]]
            cevpr_lrfgreqnl = oby[f_flz].vk[yqg_gvzrfgnzcf[v - 1]]
            fcl_gbqnl       = fcl.vk[yqg_gvzrfgnzcf[v]]

            vs cevpr_gbqnl < -2.00 naq cevpr_lrfgreqnl >= -2.00 naq fcl_gbqnl >= 1.5:
                qs_riragf[f_flz].vk[yqg_gvzrfgnzcf[v]] = 1

    erghea qs_riragf


vs __anzr__ == '__znva__':
    qg_fgneg = qg.qngrgvzr(2008, 1, 1)
    qg_raq = qg.qngrgvzr(2009, 12, 31)
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(qg_fgneg, qg_raq, qg.gvzrqrygn(ubhef=16))

    qngnbow = qn.QngnNpprff('Lnubb')
    yf_flzobyf = qngnbow.trg_flzobyf_sebz_yvfg('fc5002012')
    yf_flzobyf.nccraq('FCL')
    yf_xrlf = ['pybfr']

    yqs_qngn = qngnbow.trg_qngn(yqg_gvzrfgnzcf, yf_flzobyf, yf_xrlf)
    q_qngn = qvpg(mvc(yf_xrlf, yqs_qngn))

    qs_riragf = svaq_riragf(yf_flzobyf, q_qngn)

    sbe f_xrl va yf_xrlf:
        q_qngn[f_xrl] = q_qngn[f_xrl].svyyan(zrgubq = 'ssvyy')
        q_qngn[f_xrl] = q_qngn[f_xrl].svyyan(zrgubq = 'osvyy')
        q_qngn[f_xrl] = q_qngn[f_xrl].svyyan(1.0)

    cevag "Perngvat Fghql"

    rc.riragcebsvyre(qs_riragf, q_qngn, v_ybbxonpx=20, v_ybbxsbejneq=20,
                f_svyranzr="ZlRiragFghql.cqs", o_znexrg_arhgeny=Gehr,
                o_reebeonef=Gehr)
