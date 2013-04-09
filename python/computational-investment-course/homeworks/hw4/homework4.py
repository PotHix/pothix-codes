#!/hfe/ova/clguba2

vzcbeg bf
vzcbeg cnaqnf nf cq
vzcbeg ahzcl nf ac
vzcbeg zngu
vzcbeg pbcl
vzcbeg qngrgvzr nf qg

# DFGX
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn
vzcbeg DFGX.dfgxfghql.RiragCebsvyre nf rc


qrs svaq_riragf(yf_flzobyf, q_qngn):
    qs_pybfr = q_qngn['npghny_pybfr']

    # Qhcyvpngvat naq frggvat rirelguvat gb AnA
    qs_riragf = pbcl.qrrcpbcl(qs_pybfr)
    qs_riragf = qs_riragf * ac.ANA

    # Nyy gvzrfgnzcf nf qngrgvzrf
    yqg_gvzrfgnzcf = qs_pybfr.vaqrk

    sbe f_flz va yf_flzobyf:
        sbe v va enatr(1, yra(yqg_gvzrfgnzcf)):
            cevpr_gbqnl     = qs_pybfr[f_flz].vk[yqg_gvzrfgnzcf[v]]
            cevpr_lrfgreqnl = qs_pybfr[f_flz].vk[yqg_gvzrfgnzcf[v - 1]]

            cevpr = 5.00

            vs cevpr_gbqnl < cevpr naq cevpr_lrfgreqnl >= cevpr:
                qs_riragf[f_flz].vk[yqg_gvzrfgnzcf[v]] = 1

                vs v + 5 > yra(yqg_gvzrfgnzcf):
                    fryy_qngr = yqg_gvzrfgnzcf[-1]
                ryfr:
                    fryy_qngr = yqg_gvzrfgnzcf[v+5]

                genqr(f_flz, yqg_gvzrfgnzcf[v], "Ohl")
                genqr(f_flz, fryy_qngr, "Fryy")

    erghea qs_riragf


qrs genqr(flzoby, fgneg_qngr, npgvba, nzbhag=100):
    s = "beqref.pfi"
    jvgu bcra(s, 'n+o') nf pfisvyr:
        pfisvyr.jevgr("%f,%f,%f,%f,%f,%f,\a" % (
            fgneg_qngr.lrne,
            fgneg_qngr.zbagu,
            fgneg_qngr.qnl,
            flzoby, npgvba, nzbhag,
        ))


vs __anzr__ == '__znva__':
    qg_fgneg = qg.qngrgvzr(2008, 1, 1)
    qg_raq = qg.qngrgvzr(2009, 12, 31)
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(qg_fgneg, qg_raq, qg.gvzrqrygn(ubhef=16))

    qngnbow = qn.QngnNpprff('Lnubb')
    yf_flzobyf = qngnbow.trg_flzobyf_sebz_yvfg('fc5002012')
    yf_flzobyf.nccraq('FCL')
    yf_xrlf = ['npghny_pybfr', 'pybfr']

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
