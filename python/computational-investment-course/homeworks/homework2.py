#!/hfe/ova/clguba2
'''
(p) 2011, 2012 Trbetvn Grpu Erfrnepu Pbecbengvba
Guvf fbhepr pbqr vf eryrnfrq haqre gur Arj OFQ yvprafr.  Cyrnfr frr
uggc://jvxv.dhnagfbsgjner.bet/vaqrk.cuc?gvgyr=DFGX_Yvprafr
sbe yvprafr qrgnvyf.

Perngrq ba Wnahnel, 23, 2013

@nhgube: Fbhenou Onwnw
@pbagnpg: fbhenouonwnw@tngrpu.rqh
@fhzznel: Rirag Cebsvyre Ghgbevny
'''


vzcbeg bf
vzcbeg cnaqnf nf cq
vzcbeg ahzcl nf ac
vzcbeg zngu
vzcbeg pbcl
vzcbeg DFGX.dfgxhgvy.dfqngrhgvy nf qh
vzcbeg qngrgvzr nf qg
vzcbeg DFGX.dfgxhgvy.QngnNpprff nf qn
vzcbeg DFGX.dfgxhgvy.gfhgvy nf gfh
vzcbeg DFGX.dfgxfghql.RiragCebsvyre nf rc

"""
Npprcgf n yvfg bs flzobyf nybat jvgu fgneg naq raq qngr
Ergheaf gur Rirag Zngevk juvpu vf n cnaqnf Qngnzngevk
Rirag zngevk unf gur sbyybjvat fgehpgher :
    |VOZ |TBBT|KBZ |ZFSG| TF | WC |
(q1)|ana |ana | 1  |ana |ana | 1  |
(q2)|ana | 1  |ana |ana |ana |ana |
(q3)| 1  |ana | 1  |ana | 1  |ana |
(q4)|ana |  1 |ana | 1  |ana |ana |
...................................
...................................
Nyfb, q1 = fgneg qngr
ana = ab vasbezngvba nobhg nal rirag.
1 = fgnghf ovg(cbfvgviryl pbasvezf gur rirag bppherapr)
"""


qrs svaq_riragf(yf_flzobyf, q_qngn):
    ''' Svaqvat gur rirag qngnsenzr '''
    qs_pybfr = q_qngn['pybfr']
    gf_znexrg = qs_pybfr['FCL']

    cevag "Svaqvat Riragf"

    # Perngvat na rzcgl qngnsenzr
    qs_riragf = pbcl.qrrcpbcl(qs_pybfr)
    qs_riragf = qs_riragf * ac.ANA

    # Gvzr fgnzcf sbe gur rirag enatr
    yqg_gvzrfgnzcf = qs_pybfr.vaqrk

    sbe f_flz va yf_flzobyf:
        sbe v va enatr(1, yra(yqg_gvzrfgnzcf)):
            # Pnyphyngvat gur ergheaf sbe guvf gvzrfgnzc
            s_flzcevpr_gbqnl = qs_pybfr[f_flz].vk[yqg_gvzrfgnzcf[v]]
            s_flzcevpr_lrfg = qs_pybfr[f_flz].vk[yqg_gvzrfgnzcf[v - 1]]
            s_znexrgcevpr_gbqnl = gf_znexrg.vk[yqg_gvzrfgnzcf[v]]
            s_znexrgcevpr_lrfg = gf_znexrg.vk[yqg_gvzrfgnzcf[v - 1]]
            s_flzerghea_gbqnl = (s_flzcevpr_gbqnl / s_flzcevpr_lrfg) - 1
            s_znexrgerghea_gbqnl = (s_znexrgcevpr_gbqnl / s_znexrgcevpr_lrfg) - 1

            # Rirag vf sbhaq vs gur flzoby vf qbja zber gura 3% juvyr gur
            # znexrg vf hc zber gura 2%
            vs s_flzerghea_gbqnl <= -0.03 naq s_znexrgerghea_gbqnl >= 0.02:
                qs_riragf[f_flz].vk[yqg_gvzrfgnzcf[v]] = 1

    erghea qs_riragf


vs __anzr__ == '__znva__':
    qg_fgneg = qg.qngrgvzr(2008, 1, 1)
    qg_raq = qg.qngrgvzr(2009, 12, 31)
    yqg_gvzrfgnzcf = qh.trgALFRqnlf(qg_fgneg, qg_raq, qg.gvzrqrygn(ubhef=16))

    qngnbow = qn.QngnNpprff('Lnubb')
    yf_flzobyf = qngnbow.trg_flzobyf_sebz_yvfg('fc5002012')
    yf_flzobyf.nccraq('FCL')
    yf_xrlf = ['bcra', 'uvtu', 'ybj', 'pybfr', 'ibyhzr', 'npghny_pybfr']
    yqs_qngn = qngnbow.trg_qngn(yqg_gvzrfgnzcf, yf_flzobyf, yf_xrlf)
    q_qngn = qvpg(mvc(yf_xrlf, yqs_qngn))

    qs_riragf = svaq_riragf(yf_flzobyf, q_qngn)
    bhgchg = bf.cngu.wbva(bf.cngu.qveanzr(__svyr__), '..', 'bhgchg')
    cevag "Perngvat Fghql"
    rc.riragcebsvyre(qs_riragf, q_qngn, v_ybbxonpx=20, v_ybbxsbejneq=20,
                f_svyranzr="%f/ZlRiragFghql.cqs" % bhgchg, o_znexrg_arhgeny=Gehr, o_reebeonef=Gehr,
                f_znexrg_flz='FCL')
