/*
 * Copyright (c) 2021, salesforce.com, inc.
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 * For full license text, see the LICENSE.txt file in the repo root or https://opensource.org/licenses/BSD-3-Clause
 */
#include "client_result.h"

void ClientResult::OutputStat(StrDict* varList)
{
	m_Data.client = varList->GetVar("Client")->Text();

	int i = 0;
	StrPtr* view = nullptr;

	while (true)
	{
		std::string indexString = std::to_string(i++);
		view = varList->GetVar(("View" + indexString).c_str());

		if (!view)
		{
			break;
		}

		m_Data.mapping.push_back(view->Text());
	}
}
