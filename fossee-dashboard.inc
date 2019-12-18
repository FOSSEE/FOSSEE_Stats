<?php
function fossee_dashboard_form($form, &$form_state) {
	global $user;
	/************************ start approve book details ************************/
	if ($user->uid == 0)
	{
		$msg = drupal_set_message(t('It is mandatory to ' . l('login', 'user') . ' on this website to access the case study proposal form. If you are new user please create a new account first.'), 'error');
		drupal_goto('user');
		return $msg;
	}
	$form['#attributes'] = array(
		'enctype' => "multipart/form-data"
	);
	$form['progress_tables'] = array(
		'#type' => 'item',
		'#markup' => '
		<style>
		table, td{
			border: 1px solid black;
		}
		</style><h3><span style="color:#000000"><span style="font-size:16px">FOSSEE: Project Progress</span></span></h3>

<table>
	<tbody>
		<tr>
			<td>&nbsp;</td>
			<td>
			<p><span style="color:#000000">Attribute / Outcome</span></p>
			</td>
			<td>
			<p><span style="color:#000000">April 17 - Sep 17</span></p>

			<p><span style="color:#000000">(Target: 175 )</span></p>
			</td>
			<td>
			<p><span style="color:#000000">Oct 17 – Sep 18 (Target: 1000 Institutions)&nbsp;</span></p>
			</td>
			<td>
			<p><span style="color:#000000">Oct 18 – Sep 19</span></p>

			<p><span style="color:#000000">(Target: 1000 Institutions)&nbsp;</span></p>
			</td>
		</tr>
		<tr>
			<td>
			<p><span style="color:#000000">(i)</span></p>
			</td>
			<td>
			<p><span style="color:#000000">FOSSEE Activities:&nbsp; TBC, LM DWSIM Flowsheets, OpenFOAM Case studies, eSim simulations, etc.</span></p>
			</td>
			<td>
			<p><span style="color:#000000">189&nbsp;</span></p>
			</td>
			<td>
			<p><span style="color:#000000">44</span></p>
			</td>
			<td>
			<p><span style="color:#000000">106</span></p>
			</td>
		</tr>
		<tr>
			<td>
			<p><span style="color:#000000">(ii)</span></p>
			</td>
			<td>
			<p><span style="color:#000000">Workshops and conferences</span></p>
			</td>
			<td>
			<p><span style="color:#000000">--</span></p>
			</td>
			<td>
			<p><span style="color:#000000">877</span></p>
			</td>
			<td>
			<p><span style="color:#000000">898</span></p>
			</td>
		</tr>
		<tr>
			<td>
			<p><span style="color:#000000">iii)</span></p>
			</td>
			<td>
			<p><span style="color:#000000">Fellowship</span></p>
			</td>
			<td>
			<p><span style="color:#000000">--</span></p>
			</td>
			<td>
			<p><span style="color:#000000">200</span></p>
			</td>
			<td>
			<p><span style="color:#000000">250</span></p>
			</td>
		</tr>
		<tr>
			<td>
			<p><span style="color:#000000">(iv)</span></p>
			</td>
			<td>
			<p><span style="color:#000000">Online evaluator</span></p>
			</td>
			<td>
			<p><span style="color:#000000">--</span></p>
			</td>
			<td>
			<p><span style="color:#000000">89</span></p>
			</td>
			<td>
			<p><span style="color:#000000">48</span></p>
			</td>
		</tr>
		<tr>
			<td>&nbsp;</td>
			<td>
			<p><span style="color:#000000">Total</span></p>
			</td>
			<td>
			<p><span style="color:#000000">189</span></p>
			</td>
			<td>
			<p><span style="color:#000000">1363</span></p>
			</td>
			<td>
			<p><span style="color:#000000">1302</span></p>
			</td>
		</tr>
		<tr>
			<td>&nbsp;</td>
			<td colspan="4">
			<p><span style="color:#000000">Oct 19 – Mar 20: target 500 Institutions</span></p>
			</td>
		</tr>
	</tbody>
</table>

<p>Financial Progress</p>
<table>
<tbody>
<tr>
<td>
<p><strong>Period</strong></p>
</td>
<td>
<p><strong>Funds received (release date)</strong></p>
</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>
<p><strong>2017-18</strong></p>
</td>
<td>
<p><span style="font-weight: 400;">3,27,14,076 (Cash in hand as on 1 April 2017)</span></p>
<p><span style="font-weight: 400;">3 Cr. (15.01.2018)</span></p>
</td>
<td>
<p><span style="font-weight: 400;"><a href="https://fossee.in/data/UC/UC-2016-2017.pdf" target="_blank">UC as on 31 March 2017</a></span></p>
</td>
</tr>
<tr>
<td>
<p><strong>2018-19</strong></p>
</td>
<td>
<p><span style="font-weight: 400;">3 Cr. (23.10.2018)</span></p>
</td>
<td>
<p><span style="font-weight: 400;"><a href="https://fossee.in/data/UC/UC-2017-2018.pdf" target="_blank">UC as on 31 March 2018</a></span></p>
</td>
</tr>
<tr>
<td>
<p><strong>2019-20</strong></p>
</td>
<td>
<p><span style="font-weight: 400;">1.52 Cr (17.06.2019)</span></p>
<p><span style="font-weight: 400;">2.38 Cr (17.09.2019)</span></p>
<p><span style="font-weight: 400;">3.09 Cr (5.11.2019)</span></p>
</td>
<td>
<p><span style="font-weight: 400;"><a href="https://fossee.in/data/UC/UC-2018-2019.pdf" target="_blank">UC as on 31 March 2019</a></span></p>
</td>
</tr>
</tbody>
</table>
'
	);
	return $form;
}